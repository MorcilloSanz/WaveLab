#include "FrameBuffer.h"

FrameBuffer::FrameBuffer() 
    : Buffer() {
}

FrameBuffer::FrameBuffer(const FrameBuffer& frameBuffer) {
    id = frameBuffer.id;
}

FrameBuffer::FrameBuffer(FrameBuffer&& frameBuffer) {
    id = frameBuffer.id;
}

FrameBuffer& FrameBuffer::operator=(const FrameBuffer& frameBuffer) {
    id = frameBuffer.id;
    return *this;
}

FrameBuffer::~FrameBuffer() { 
    unbind();
    glDeleteBuffers(1, &id);
}

void FrameBuffer::initBuffer() {
    glGenFramebuffers(1, &id);
    glBindFramebuffer(GL_FRAMEBUFFER, id);
}

void FrameBuffer::bind() {
    glBindFramebuffer(GL_FRAMEBUFFER, id);
}

void FrameBuffer::unbind() {
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
}