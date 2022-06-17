#include "Group.h"

Group::Group(unsigned int _primitive, bool _showWire) 
    : primitive(_primitive), showWire(_showWire), modelMatrix(1.f), visible(true) {
}

void Group::draw() {
    for(Polytope& polytope : polytopes)
        polytope.draw(primitive, showWire);
}