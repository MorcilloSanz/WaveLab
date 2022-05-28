#include "VertexArray.h"

#include "../../../glew/glew.h"

VertexArray::VertexArray() {
    initBuffer();
}

VertexArray::VertexArray(const VertexArray& vertexArray)
    : vertexArrayID(vertexArray.vertexArrayID) {
}

VertexArray::VertexArray(VertexArray&& vertexArray) noexcept 
    : vertexArrayID(vertexArray.vertexArrayID) {
}

VertexArray& VertexArray::operator=(const VertexArray& vertexArray) {
    vertexArrayID = vertexArray.vertexArrayID;
    return *this;
}

VertexArray::~VertexArray() {
    unbind();
    glDeleteVertexArrays(1, &vertexArrayID);
}

void VertexArray::initBuffer() {
    glGenVertexArrays(1, &vertexArrayID);
    glBindVertexArray(vertexArrayID);
}

void VertexArray::bind() {
    glBindVertexArray(vertexArrayID);
}

void VertexArray::unbind() {
    glBindVertexArray(0);
}