#include "Model.h"

Model::Model(const std::string& _path, bool _gammaCorrection) 
    : path(_path), gammaCorrection(_gammaCorrection) {
    loadModel();
}

void Model::loadModel() {
    // read file via ASSIMP
    Assimp::Importer importer;
    const aiScene* scene = importer.ReadFile(path, aiProcess_Triangulate | aiProcess_GenSmoothNormals | aiProcess_FlipUVs | aiProcess_CalcTangentSpace);
    // check for errors
    if(!scene || scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode) {
        std::cout << "ERROR::ASSIMP:: " << importer.GetErrorString() << std::endl;
        return;
    }
    // retrieve the directory path of the filepath
    path = path.substr(0, path.find_last_of('/'));
    // process ASSIMP's root node recursively
    processNode(scene->mRootNode, scene);
}

void Model::processNode(aiNode *node, const aiScene *scene) {
    // process each mesh located at the current node
    for(unsigned int i = 0; i < node->mNumMeshes; i++)
    {
        // the node object only contains indices to index the actual objects in the scene. 
        // the scene contains all the data, node is just to keep stuff organized (like relations between nodes).
        aiMesh* mesh = scene->mMeshes[node->mMeshes[i]];
        std::shared_ptr<Polytope> polytope = processMesh(mesh, scene); // may be freed?
        add(polytope);
    }
    // after we've processed all of the meshes (if any) we then recursively process each of the children nodes
    for(unsigned int i = 0; i < node->mNumChildren; i++) processNode(node->mChildren[i], scene);
}

std::shared_ptr<Polytope> Model::processMesh(aiMesh *mesh, const aiScene *scene) {
    // data to fill
    std::vector<Vec3f> vertices;
    std::vector<unsigned int> indices;
    std::vector<std::shared_ptr<Texture>> textures;   

    // walk through each of the mesh's vertices
    for(unsigned int i = 0; i < mesh->mNumVertices; i++)
    {
        Vec3f vertex;
        glm::vec3 vector; // we declare a placeholder vector since assimp uses its own vector class that doesn't directly convert to glm's vec3 class so we transfer the data to this placeholder glm::vec3 first.
        // positions
        vertex.x = vector.x = mesh->mVertices[i].x;
        vertex.y = vector.y = mesh->mVertices[i].y;
        vertex.z = vector.z = mesh->mVertices[i].z;

        // normals
        if (mesh->HasNormals()) {
            vertex.nx = vector.x = mesh->mNormals[i].x;
            vertex.ny = vector.y = mesh->mNormals[i].y;
            vertex.nz = vector.z = mesh->mNormals[i].z;
        }
        // texture coordinates
        if(mesh->mTextureCoords[0]) // does the mesh contain texture coordinates?
        {
            glm::vec2 vec;
            // a vertex can contain up to 8 different texture coordinates. We thus make the assumption that we won't 
            // use models where a vertex can have multiple texture coordinates so we always take the first set (0).
            vertex.tx = vec.x = mesh->mTextureCoords[0][i].x; 
            vertex.ty = vec.y = mesh->mTextureCoords[0][i].y;
            // tangent
            /*
            vector.x = mesh->mTangents[i].x;
            vector.y = mesh->mTangents[i].y;
            vector.z = mesh->mTangents[i].z;
            vertex.Tangent = vector;
            // bitangent
            vector.x = mesh->mBitangents[i].x;
            vector.y = mesh->mBitangents[i].y;
            vector.z = mesh->mBitangents[i].z;
            vertex.Bitangent = vector;
            */
        }
        else vertex.tx = vertex.ty = 0.0f;
        vertices.push_back(vertex);
    }
    // now wak through each of the mesh's faces (a face is a mesh its triangle) and retrieve the corresponding vertex indices.
    for(unsigned int i = 0; i < mesh->mNumFaces; i++)
    {
        aiFace face = mesh->mFaces[i];
        // retrieve all indices of the face and store them in the indices vector
        for(unsigned int j = 0; j < face.mNumIndices; j++)
            indices.push_back(face.mIndices[j]);        
    }
    // process materials
    aiMaterial* material = scene->mMaterials[mesh->mMaterialIndex];    
    // we assume a convention for sampler names in the shaders. Each diffuse texture should be named
    // as 'texture_diffuseN' where N is a sequential number ranging from 1 to MAX_SAMPLER_NUMBER. 
    // Same applies to other texture as the following list summarizes:
    // diffuse: texture_diffuseN
    // specular: texture_specularN
    // normal: texture_normalN

    // 1. diffuse maps
    std::vector<std::shared_ptr<Texture>> diffuseMaps = loadMaterialTextures(material, aiTextureType_DIFFUSE, "texture_diffuse");
    textures.insert(textures.end(), diffuseMaps.begin(), diffuseMaps.end());
    // 2. specular maps
    std::vector<std::shared_ptr<Texture>>  specularMaps = loadMaterialTextures(material, aiTextureType_SPECULAR, "texture_specular");
    textures.insert(textures.end(), specularMaps.begin(), specularMaps.end());
    // 3. normal maps
    std::vector<std::shared_ptr<Texture>>  normalMaps = loadMaterialTextures(material, aiTextureType_HEIGHT, "texture_normal");
    textures.insert(textures.end(), normalMaps.begin(), normalMaps.end());
    // 4. height maps
    std::vector<std::shared_ptr<Texture>>  heightMaps = loadMaterialTextures(material, aiTextureType_AMBIENT, "texture_height");
    textures.insert(textures.end(), heightMaps.begin(), heightMaps.end());
    
    // return a mesh object created from the extracted mesh data
    std::shared_ptr<Polytope> polytope = std::make_shared<Polytope>(vertices, indices);
    for(auto& texture : textures) polytope->addTexture(texture);
    return polytope;
}

std::vector<std::shared_ptr<Texture>> Model::loadMaterialTextures(aiMaterial *mat, aiTextureType type, const std::string& typeName) {
    std::vector<std::shared_ptr<Texture>> textures;
    for(unsigned int i = 0; i < mat->GetTextureCount(type); i++) {
        aiString str;
        mat->GetTexture(type, i, &str);
        // check if texture was loaded before and if so, continue to next iteration: skip loading a new texture
        bool skip = false;
        for(unsigned int j = 0; j < texturesLoaded.size(); j++) {
            if(std::strcmp(texturesLoaded[j]->getPath().data(), str.C_Str()) == 0) {
                textures.push_back(texturesLoaded[j]);
                skip = true; // a texture with the same filepath has already been loaded, continue to next one. (optimization)
                break;
            }
        }
        if(!skip) {   // if texture hasn't been loaded already, load it
            std::shared_ptr<Texture> texture = std::make_shared<Texture>(this->path);
            if(typeName == "texture_diffuse") texture->setType(Texture::Type::TextureDiffuse);
            else if(typeName == "texture_specular") texture->setType(Texture::Type::TextureSpecular);
            textures.push_back(texture);
            texturesLoaded.push_back(texture);  // store it as texture loaded for entire model, to ensure we won't unnecesery load duplicate textures.
        }
    }
    return textures;
}