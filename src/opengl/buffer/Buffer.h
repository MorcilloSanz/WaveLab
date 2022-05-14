#pragma once

class Buffer {
protected:
    virtual void initBuffer() = 0;
public:
    virtual void bind() = 0;
    virtual void unbind() = 0;
};