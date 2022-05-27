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
    std::vector<Group> groups;
    Camera camera;
    bool hasCamera;
public:
    Renderer();
    ~Renderer() = default;
private:
    void enableBlending();
    void enableAntialiasing();
public:
    void setCamera(const Camera& camera);
    void render();
    void clear();
public:
    inline void addGroup(const Group& group) {
        groups.push_back(group);
    }

    inline Camera& getCamera() {
        return camera;
    }

    inline std::vector<Group>& getGroups() {
        return groups;
    }

    inline std::shared_ptr<ShaderProgram>& getShaderProgram() {
        return shaderProgram;
    }
};