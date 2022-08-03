#pragma once

#include <iostream>

#include "../../../glew/glew.h"

class Texture {
public:
    enum class Type {
        None, TextureDiffuse, TextureSpecular, TextureNormal, TextureHeight
    };
    static int textureUnits;
protected:
    static unsigned int count;
    int slot;
    unsigned int id;
    int width, height, bpp;
    std::string path;
    Type type;
public:
    Texture(const std::string& _path, const Type& _type = Type::None);
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
    inline void setID(unsigned int id) { this->id = id; }
    inline unsigned int getID() const { return id; }

    inline void setPath(const std::string& path) { this->path = path; }
    inline const std::string& getPath() { return path; }

    inline void setSlot(int slot) { this->slot = slot; }
	inline int getSlot() const { return slot; }

    inline void setType(const Type& type) { this->type = type; }
    inline Type& getType() { return type; }

    static unsigned int getCount() { return count; }
};