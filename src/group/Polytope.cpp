#include "Polytope.h"

#include "../../glew/glew.h"

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

void Polytope::draw(unsigned int primitive, bool showWire) {
    bind();
    if(!showWire)   glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    else            glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glDrawArrays(GL_TRIANGLES, 0, 3);
    unbind();
}