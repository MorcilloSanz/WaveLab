#include "Group.h"

Group::Group() 
    : visible(true) {
}

void Group::draw(unsigned int primitive, bool showWire) {
    for(Polytope& polytope : polytopes)
        polytope.draw(primitive, showWire);
}