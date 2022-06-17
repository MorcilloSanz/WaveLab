#pragma once

#include <iostream>
#include <vector>
#include <memory>

#include "Buffer.h"
#include "IndexBuffer.h"

template<typename T>
struct Vec3 {
    T x, y, z;
    float r, g, b;

    Vec3(T _x, T _y, T _z, float _r = 255, float _g = 255, float _b = 255)
        : x(_x), y(_y), z(_z), r(_r), g(_g), b(_b) {
    }
    Vec3() : x(0), y(0), z(0), r(0), g(0), b(0) {}
    ~Vec3() = default;
};
typedef Vec3<float> Vec3f;
typedef Vec3<int> Vec3i;

class VertexBuffer : public Buffer {
private:
    std::vector<Vec3f> vertices;
    std::vector<unsigned int> indices;
    std::shared_ptr<IndexBuffer> indexBuffer;
    bool hasIndexBuffer;
public:
    VertexBuffer();
    VertexBuffer(const std::vector<Vec3f>& _vertices);
    VertexBuffer(const std::vector<Vec3f>& _vertices, const std::vector<unsigned int> _indices);
    VertexBuffer(const VertexBuffer& vertexBuffer);
    VertexBuffer(VertexBuffer&& vertexBuffer) noexcept;
    VertexBuffer& operator=(const VertexBuffer& vertexBuffer);
    ~VertexBuffer();
protected:
    void initBuffer() override;
public:
    void updateVertices(std::vector<Vec3f>& vertices, bool copy2memory = false);
    void bind() override;
    void unbind() override;
public:
    inline std::vector<Vec3f>& getVertices() {
        return vertices;
    }

    inline float* getMapBuffer() {
        return (float*)glMapBuffer(GL_ARRAY_BUFFER, GL_READ_ONLY);
    }

    inline std::shared_ptr<IndexBuffer>& getIndexBuffer() {
        return indexBuffer;
    }

    inline bool HasIndexBuffer() const {
        return hasIndexBuffer;
    }
};