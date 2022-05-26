#include "Polytope.h"

Polytope::Polytope(const std::vector<Vec3f>& vertices) 
    : visible(true) {
    vertexArray = std::make_shared<VertexArray>();
    vertexBuffer = std::make_shared<VertexBuffer>(vertices);
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