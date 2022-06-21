#include "TrackballCamera.h"

#include <iostream>

TrackballCamera::TrackballCamera(const glm::mat4& projectionMatrix, const glm::mat4& viewMatrix)
    : Camera(projectionMatrix, viewMatrix), theta(M_PI_2), phi(M_PI_2), radius(0) {
}

TrackballCamera TrackballCamera::orthoCamera(float left, float right, float bottom, float top, float zNear, float zFar) {
    glm::mat4 projection = glm::ortho(left, right, bottom, top, zNear, zFar);
    glm::mat4 view(1.0f);
    TrackballCamera camera(projection, view);
    camera.lookAt(glm::vec3(0, 0, 1), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0));
    return camera;
}

TrackballCamera TrackballCamera::perspectiveCamera(float fovy, float aspect, float zNear, float zFar) {
    glm::mat4 projection = glm::perspective(fovy, aspect, zNear, zFar);
    glm::mat4 view(1.0f);
    TrackballCamera camera(projection, view);
    camera.lookAt(glm::vec3(0, 0, 1), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0));
    return camera;
}

glm::vec4 TrackballCamera::toCartesianCoords() {
    return glm::vec4(
        radius * sinf(phi) * sinf(theta), 
        radius * cosf(phi), 
        radius * sinf(phi) * cosf(theta), 
        1    
    );
}

glm::vec3 TrackballCamera::getCameraPosition() {
    glm::vec4 cartesianCoords = toCartesianCoords();
    glm::vec3 cameraPosition(center.x + cartesianCoords.x, center.y + cartesianCoords.y, center.z + cartesianCoords.z);
    return cameraPosition;
}

glm::mat4& TrackballCamera::getViewMatrix() {
    eye = getCameraPosition();
    lookAt(eye, center, up);
    return viewMatrix;
}

void TrackballCamera::rotate(float dTheta, float dPhi) {
    if (up.y > 0.0f)    theta += dTheta;
	else                theta -= dTheta;

    phi += dPhi;

    if(phi > 2 * M_PI) phi -= 2 * M_PI;
    else if(phi < -2 * M_PI) phi += 2 * M_PI;
}

void TrackballCamera::pan(float dx, float dy) {

}

void TrackballCamera::zoom(float dRadius) {
    radius -= dRadius;
}