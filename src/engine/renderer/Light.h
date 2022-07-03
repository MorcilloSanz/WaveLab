#pragma once

#include <iostream>
#include <memory>

#include "../../../glm/vec3.hpp"
#include "../../../glm/vec4.hpp"
#include "../../../glm/mat4x4.hpp"
#include "../../../glm/gtc/type_ptr.hpp"

#include "../opengl/shader/Shader.h"

class Light {
private:
    glm::vec3 lightPosition;
    glm::vec3 cameraPosition;   // view pos
    glm::vec3 lightColor;
    std::shared_ptr<ShaderProgram> shaderProgram;
    int shininess;
    float ambientStrength, specularStrength;
public:
    Light(const glm::vec3& _lightPosition);
    ~Light() = default;
public:
    inline glm::vec3& getLightPosition() { return lightPosition; }
    inline glm::vec3& getCameraPosition() { return cameraPosition; }
    inline glm::vec3& getLightColor() { return lightColor; }

    inline void setLightPosition(const glm::vec3& lightPosition) { this->lightPosition = lightPosition; }
    inline void setCameraPosition(const glm::vec3& cameraPosition) { this->cameraPosition = cameraPosition; }
    inline void setLightColor(const glm::vec3& lightColor) { this->lightColor = lightColor; }
    /**
     * @brief shininess: 2, 4, 8, 16, 32, 64, ..., 256
     * 
     * @param shininess 
     */
    inline void setShininess(int shininess) { this->shininess = shininess; }
    inline int getShininess() const {  return shininess; }

    inline void setAmbientStrength(float ambientStrength) { this->ambientStrength = ambientStrength; }
    inline float getAmbientStrength() const { return ambientStrength; }

    inline void setSpecularStrength(float specularStrength) { this->specularStrength = specularStrength; }
    inline float getSpecularStrength() const { return specularStrength; }

    inline std::shared_ptr<ShaderProgram>& getShaderProgram() { return shaderProgram; }
};