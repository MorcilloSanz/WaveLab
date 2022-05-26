#pragma once

#include <iostream>
#include <vector>

#include "Polytope.h"

class Group {
private:
    std::vector<Polytope> polytopes;
    bool visible;
public:
    Group();
    ~Group() = default;
public:
    void draw(unsigned int primitive, bool showWire = false);
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
};