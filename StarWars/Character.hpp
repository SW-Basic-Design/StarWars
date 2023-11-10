#include "Object.hpp"

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

class Character : public Object {
public:
	Character();
	~Character() = default;
	void setHealth(const int h);
	void giveDamage(const int d);
protected:
	int speed;
	int health;
};

#endif