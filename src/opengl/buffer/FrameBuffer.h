#pragma once

#include "Buffer.h"

class FrameBuffer : public Buffer {
public:
    FrameBuffer();
    FrameBuffer(const FrameBuffer& frameBuffer);
    FrameBuffer(FrameBuffer&& frameBuffer);
    FrameBuffer& operator=(const FrameBuffer& frameBuffer);
    ~FrameBuffer();
private:
    void initBuffer() override;
public:
    void bind() override;
    void unbind() override;
};