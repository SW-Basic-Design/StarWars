#include "Object.hpp"

#ifndef PARTICLE_HPP
#define PARTICLE_HPP

class Particle: public Object {
public:
	Particle();
	~Particle() = default;
	void setDamage(const int d);
	int getDamage();
private :
	int damage;

};

#endif