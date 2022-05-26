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
    bool visible;
public:
    Polytope(const std::vector<Vec3f>& vertices);
    Polytope() = default;
    ~Polytope() = default;
public:
    void bind();
    void unbind();
public:
    inline std::shared_ptr<VertexArray>& getVertexArray() {
        return vertexArray;
    }

    inline std::shared_ptr<VertexBuffer>& getVertexBuffer() {
        return vertexBuffer;
    }

    inline void setVisible(bool visible) {
        this->visible = visible;
    }

    inline bool isVisible() const {
        return visible;
    }
};