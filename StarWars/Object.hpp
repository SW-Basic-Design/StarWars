#include "Vec2.hpp"

#ifndef OBJECT_HPP
#define OBJECT_HPP

class Object {
public :
	Object();
	Object(bool);
	Object(bool, Vec2);
	Vec2& getCoord();

protected:
	bool isFixed;
	Vec2 coord;
};

#endif