#include "Group.h"

Group::Group(unsigned int _primitive, bool _showWire) 
    : primitive(_primitive), showWire(_showWire), visible(true) {
}

void Group::draw() {
    for(Polytope& polytope : polytopes)
        polytope.draw(primitive, showWire);
}