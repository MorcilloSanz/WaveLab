#include "Light.h"

#include "../../../glew/glew.h"

Light::Light(const glm::vec3& _lightPosition) 
    : lightPosition(_lightPosition), cameraPosition(glm::vec3(0, 0, 0)), lightColor(glm::vec3(1, 1, 1)), shininess(32) {
    Shader vertexShader = Shader::fromFile("../src/engine/opengl/glsl/phong_vertex.glsl", Shader::ShaderType::Vertex);
    Shader fragmentShader = Shader::fromFile("../src/engine/opengl/glsl/phong_fragment.glsl", Shader::ShaderType::Fragment);
    shaderProgram = std::make_shared<ShaderProgram>(vertexShader, fragmentShader);
}