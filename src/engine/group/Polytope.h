#pragma once

#include <iostream>
#include <vector>
#include <memory>

#include "../opengl/buffer/VertexArray.h"
#include "../opengl/buffer/VertexBuffer.h"

class Polytope {
private:
    std::shared_ptr<VertexArray> vertexArray;
    std::shared_ptr<VertexBuffer> vertexBuffer;
    unsigned int vertexLength, indicesLength;
public:
    Polytope(const std::vector<Vec3f>& vertices);
    Polytope(const std::vector<Vec3f>& vertices, const std::vector<unsigned int> indices);
    Polytope() = default;
    ~Polytope() = default;
public:
    void bind();
    void unbind();
    void updateVertices(std::vector<Vec3f>& vertices, bool copy2memory = false);
    void updateIndices(std::vector<unsigned int>& indices, bool copy2memory = false);
    void draw(unsigned int primitive, bool showWire = false);
public:
    inline std::shared_ptr<VertexArray>& getVertexArray() {
        return vertexArray;
    }

    inline std::shared_ptr<VertexBuffer>& getVertexBuffer() {
        return vertexBuffer;
    }

    inline unsigned int getVertexLength() const {
        return vertexLength;
    }
};