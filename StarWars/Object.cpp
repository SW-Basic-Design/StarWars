#include "Object.hpp"

Object::Object() : Object(false, { 0, 0 }) {}

Object::Object(bool isFixed, Vec2 coord) : isFixed(isFixed), coord(coord) {}

Vec2& Object::GetCoord() {
	return this->coord;
}