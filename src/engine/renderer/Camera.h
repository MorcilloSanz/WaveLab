#pragma once

#include "../../../glm/vec3.hpp"
#include "../../../glm/vec4.hpp"
#include "../../../glm/mat4x4.hpp"
#include "../../../glm/gtc/type_ptr.hpp"

class Camera {
protected:
    glm::mat4 projectionMatrix;
    glm::mat4 viewMatrix;
    glm::vec3 eye, center, up;
    Camera(const glm::mat4& _projectionMatrix, const glm::mat4& _viewMatrix);
public:
    Camera() = default;
    ~Camera() = default;
public:
    virtual void lookAt(const glm::vec3& eye, const glm::vec3& center, const glm::vec3& up);
    virtual glm::mat4& getViewMatrix() { return viewMatrix; }

    inline glm::mat4& getProjectionMatrix() { return projectionMatrix; }
    inline void setViewMatrix(const glm::mat4& viewMatrix) { this->viewMatrix = viewMatrix; } 

    inline glm::vec3& getEye() { return eye; }
    inline glm::vec3& getCenter() { return center; }
    inline glm::vec3& getUp() { return up; }
};