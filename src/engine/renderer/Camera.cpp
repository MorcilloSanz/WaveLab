#include "Camera.h"

Camera::Camera(const glm::mat4& _projectionMatrix, const glm::mat4& _viewMatrix) 
    : projectionMatrix(_projectionMatrix), viewMatrix(_viewMatrix) {
}

Camera Camera::orthoCamera(float left, float right, float bottom, float top, float zNear, float zFar) {
    glm::mat4 projection = glm::ortho(left, right, bottom, top, zNear, zFar);
    glm::mat4 view(1.0f);
    return Camera(projection, view);
}

Camera Camera::perspectiveCamera(float fovy, float aspect, float zNear, float zFar) {
    glm::mat4 projection = glm::perspective(fovy, aspect, zNear, zFar);
    glm::mat4 view(1.0f);
    return Camera(projection, view);
}