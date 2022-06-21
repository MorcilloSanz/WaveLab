#pragma once

#include "Camera.h"

class TrackballCamera : public Camera {
private:
    float theta, phi;
    float radius;
    TrackballCamera(const glm::mat4& projectionMatrix, const glm::mat4& viewMatrix);
private:
    glm::vec4 toCartesianCoords();
    glm::vec3 getCameraPosition();
public:
    TrackballCamera() = default;
    ~TrackballCamera() = default;
    
    static TrackballCamera orthoCamera(float left, float right, float bottom, float top, float zNear, float zFar);
    static TrackballCamera perspectiveCamera(float fovy, float aspect, float zNear, float zFar);

    virtual glm::mat4& getViewMatrix() override;

    void rotate(float dTheta, float dPhi);
    void pan(float dx, float dy);
    void zoom(float dRadius);
};