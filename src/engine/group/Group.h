#pragma once

#include <iostream>
#include <vector>

#include "../../../glm/vec3.hpp"
#include "../../../glm/vec4.hpp"
#include "../../../glm/mat4x4.hpp"
#include "../../../glm/gtc/type_ptr.hpp"

#include "Polytope.h"

class Group {
private:
    std::vector<Polytope> polytopes;
    unsigned int primitive;
    bool showWire, visible;
    glm::mat4 modelMatrix;
public:
    Group(unsigned int _primitive, bool _showWire = false);
    ~Group() = default;
public:
    void draw();
public:
    inline void translate(const glm::vec3& v) {
        modelMatrix = glm::translate(modelMatrix, v);
    }

    inline void rotate(float degrees, const glm::vec3& axis) {
        modelMatrix = glm::rotate(modelMatrix, glm::radians(degrees), axis);
    }

    inline void scale(const glm::vec3& s) {
        modelMatrix = glm::scale(modelMatrix, s);
    }
public:
    inline void add(const Polytope& polytope) {
        polytopes.push_back(polytope);
    }

    inline std::vector<Polytope>& getPolytopes() {
        return polytopes;
    }

    inline void setVisible(bool visible) {
        this->visible = visible;
    }

    inline bool isVisible() const {
        return visible;
    }

    inline void setShowWire(bool showWire) {
        this->showWire = showWire;
    }

    inline bool isShowWire() const {
        return showWire;
    }

    inline void setPrimitive(unsigned int primitive) {
        this->primitive = primitive;
    }

    inline unsigned int getPrimitive() const {
        return primitive;
    }

    inline glm::mat4& getModelMatrix() {
        return modelMatrix;
    }
};