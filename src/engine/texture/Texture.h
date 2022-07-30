#pragma once

#include <iostream>

#include "../../../glew/glew.h"

class Texture {
protected:
    static unsigned int count;
    int slot;
    unsigned int id;
    int width, height, bpp;
    std::string path;
public:
    Texture(const std::string& _path);
    Texture();
    Texture(const Texture& texture);
    Texture(Texture&& texture) noexcept;
    ~Texture();
    Texture& operator=(const Texture& texture);
private:
    void generateTexture();
public:
    virtual void bind();
    virtual void unbind();
public:
    inline unsigned int getID() const { return id; }
    inline const std::string& getPath() { return path; }
	inline int getSlot() const { return slot; }
    static unsigned int getCount() { return count; }
};