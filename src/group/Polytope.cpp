#include "Polytope.h"

#include "../../glew/glew.h"

Polytope::Polytope(const std::vector<Vec3f>& vertices)
    : vertexLength(vertices.size()), indicesLength(0) {
    vertexArray = std::make_shared<VertexArray>();
    vertexBuffer = std::make_shared<VertexBuffer>(vertices);
    unbind();
}

Polytope::Polytope(const std::vector<Vec3f>& vertices, const std::vector<unsigned int> indices) 
    : vertexLength(vertices.size()), indicesLength(indices.size()) {
    vertexArray = std::make_shared<VertexArray>();
    vertexBuffer = std::make_shared<VertexBuffer>(vertices, indices);
    unbind();
}

void Polytope::bind() {
    if(vertexArray != nullptr && vertexBuffer != nullptr) {
        vertexArray->bind();
    }
}

void Polytope::unbind() {
    if(vertexArray != nullptr && vertexBuffer != nullptr) {
        vertexArray->unbind();
        vertexBuffer->unbind();
    }
}

void Polytope::updateVertices(std::vector<Vec3f>& vertices) {
    if(vertexBuffer != nullptr) {
        vertexBuffer->updateVertices(vertices);
        vertexLength = vertices.size();
    }
}

void Polytope::draw(unsigned int primitive, bool showWire) {
    bind();
    if(!showWire)   glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    else            glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    if(!vertexBuffer->HasIndexBuffer()) glDrawArrays(primitive, 0, vertexLength);
    else    glDrawElements(primitive, indicesLength, GL_UNSIGNED_INT, 0);
    unbind();
}