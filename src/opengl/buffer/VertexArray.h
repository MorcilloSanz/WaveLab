#pragma once

#include "Buffer.h"

class VertexArray : public Buffer {
private:
    unsigned int vertexArrayID;
public:
    VertexArray();
    ~VertexArray();
protected:
    void initBuffer() override;
public:
    void bind() override;
    void unbind() override;
public:
    unsigned int getVertexArrayID() const {
        return vertexArrayID;
    }
};