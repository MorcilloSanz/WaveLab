#pragma once

#include "../../glm/vec3.hpp"
#include "../../glm/vec4.hpp"
#include "../../glm/mat4x4.hpp"
#include "../../glm/gtc/type_ptr.hpp"

class Camera {
private:
    glm::mat4 projectionMatrix;
    glm::mat4 viewMatrix;
    Camera(const glm::mat4& _projectionMatrix, const glm::mat4& _viewMatrix);
public:
    Camera() = default;
    ~Camera() = default;
    static Camera orthoCamera(float left, float right, float bottom, float top, float zNear, float zFar);
    static Camera perspectiveCamera(float fovy, float aspect, float zNear, float zFar);
public:
    inline void lookAt(const glm::vec3& eye, const glm::vec3& center, const glm::vec3& up) {
        viewMatrix = glm::lookAt(eye, center, up);
    }

    inline glm::mat4& getProjectionMatrix() {
        return projectionMatrix;
    }

    inline glm::mat4& getViewMatrix() {
        return viewMatrix;
    }
};