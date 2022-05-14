#include "VertexBuffer.h"

#include <string.h>

#include "../../../glew/glew.h"

VertexBuffer::VertexBuffer() : vertexBufferID(0) {
    initBuffer();
}

VertexBuffer::VertexBuffer(const std::vector<Vec3f>& _vertices)
    : vertices(_vertices), vertexBufferID(0) {
    initBuffer();
}

VertexBuffer::~VertexBuffer() {
    unbind();
    glDeleteBuffers(1, &vertexBufferID);
}

void VertexBuffer::initBuffer() {
    // Load vertices
    unsigned int index = 0;
    float* glVertices = new float[vertices.size() * 6];
    for(Vec3f& vertex : vertices) {
        glVertices[index] = vertex.x;   glVertices[index + 1] = vertex.y;   glVertices[index + 2] = vertex.z;
        glVertices[index + 3] = vertex.r;   glVertices[index + 4] = vertex.g;   glVertices[index + 5] = vertex.b;
        index += 6;
    }
    // Vertex buffer
    glGenBuffers(1, &vertexBufferID);
    glBindBuffer(GL_ARRAY_BUFFER, vertexBufferID);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float) * 6, glVertices, GL_DYNAMIC_DRAW);
    delete[] glVertices;
    // position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    // color attribute
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
}

void VertexBuffer::updateVertices(std::vector<Vec3f>& vertices) {
    glBindBuffer(GL_ARRAY_BUFFER, vertexBufferID);
    float* ptr = (float*)glMapBuffer(GL_ARRAY_BUFFER, GL_WRITE_ONLY);

    unsigned int index = 0;
    for(Vec3f& vertex : vertices) {
        ptr[index] = vertex.x;     ptr[index + 1] = vertex.y; ptr[index + 2] = vertex.z;
        ptr[index + 3] = vertex.r; ptr[index + 4] = vertex.g; ptr[index + 5] = vertex.b;
        index += 6;
    }

    glUnmapBuffer(GL_ARRAY_BUFFER);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void VertexBuffer::bind() {
    glBindBuffer(GL_ARRAY_BUFFER, vertexBufferID);
}

void VertexBuffer::unbind() {
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}