#include "Group.h"

Group::Group(unsigned int _primitive, bool _showWire) 
    : primitive(_primitive), showWire(_showWire), modelMatrix(1.f), visible(true), pointSize(1), lineWidth(1) {
}

void Group::draw() {
    for(Polytope& polytope : polytopes)
        polytope.draw(primitive, showWire);
}