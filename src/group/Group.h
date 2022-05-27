#pragma once

#include <iostream>
#include <vector>

#include "Polytope.h"

class Group {
private:
    std::vector<Polytope> polytopes;
    unsigned int primitive;
    bool showWire, visible;
public:
    Group(unsigned int _primitive, bool _showWire = false);
    ~Group() = default;
public:
    void draw();
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
};