#pragma once

#include <iostream>
#include <vector>
#include <memory>

#include "../group/Group.h"
#include "../opengl/shader/Shader.h"

#include "Camera.h"

class Renderer {
private:
    std::shared_ptr<ShaderProgram> shaderProgram;
    std::vector<Group*> groups;
    Camera camera;
    bool hasCamera;
public:
    Renderer();
    ~Renderer() = default;
public:
    void setCamera(const Camera& camera);
    void enableBlending();
    void enableAntialiasing();
    void render();
    void clear();
public:
    inline void addGroup(Group& group) {
        groups.push_back(&group);
    }

    inline void removeGroup(int index) {
        groups.erase(groups.begin() + index);
    }

    inline Group* getGroup(int index) {
        return groups[index];
    }

    inline Camera& getCamera() { return camera; }

    inline std::vector<Group*>& getGroups() { return groups; }

    inline std::shared_ptr<ShaderProgram>& getShaderProgram() { return shaderProgram; }
};