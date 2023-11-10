#include "Object.hpp"

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

class Character : public Object {
public:
	Character() : Object() {}
	~Character() = default;
protected:
	int speed;
	int health;
};

#endif