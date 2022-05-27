#pragma once

#include <iostream>
#include <vector>
#include <memory>

#include "../group/Group.h"
#include "../opengl/shader/Shader.h"

class Renderer {
private:
    std::shared_ptr<ShaderProgram> shaderProgram;
    std::vector<Group> groups;
public:
    Renderer();
    ~Renderer() = default;
private:
    void enableBlending();
    void enableAntialiasing();
public:
    void render();
    void clear();
public:
    inline void addGroup(const Group& group) {
        groups.push_back(group);
    }

    inline std::vector<Group>& getGroups() {
        return groups;
    }

    inline std::shared_ptr<ShaderProgram>& getShaderProgram() {
        return shaderProgram;
    }
};