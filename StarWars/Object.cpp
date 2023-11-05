#include "Object.hpp"

Object::Object(bool isFixed, Vec2 coord) {
	this->isFixed = isFixed;
	this->coord = coord;
}

Object::Object(bool isFixed) : Object(isFixed, { 0, 0 }) {}

Object::Object() : Object(false, { 0, 0 }) {}

Vec2& Object::getCoord() {
	return this->coord;
}