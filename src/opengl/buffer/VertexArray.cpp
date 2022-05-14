#include "VertexArray.h"

#include "../../../glew/glew.h"

VertexArray::VertexArray() {
    initBuffer();
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