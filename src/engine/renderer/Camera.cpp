#include "Camera.h"

Camera::Camera(const glm::mat4& _projectionMatrix, const glm::mat4& _viewMatrix) 
    : projectionMatrix(_projectionMatrix), viewMatrix(_viewMatrix), eye(glm::vec3(0, 0, 0)) {
}

Camera Camera::orthoCamera(float left, float right, float bottom, float top, float zNear, float zFar) {
    glm::mat4 projection = glm::ortho(left, right, bottom, top, zNear, zFar);
    glm::mat4 view(1.0f);
    Camera camera(projection, view);
    camera.lookAt(glm::vec3(0, 0, 1), glm::vec3(0, 0, -1), glm::vec3(0, 1, 0));
    return camera;
}

Camera Camera::perspectiveCamera(float fovy, float aspect, float zNear, float zFar) {
    glm::mat4 projection = glm::perspective(fovy, aspect, zNear, zFar);
    glm::mat4 view(1.0f);
    Camera camera(projection, view);
    camera.lookAt(glm::vec3(0, 0, 1), glm::vec3(0, 0, -1), glm::vec3(0, 1, 0));
    return camera;
}

void Camera::lookAt(const glm::vec3& eye, const glm::vec3& center, const glm::vec3& up) {
    this->eye = eye;
    this->center = center;
    this->up = up;
    viewMatrix = glm::lookAt(eye, center, up);
}