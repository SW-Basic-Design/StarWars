#include "Object.hpp"

#ifndef PARTICLE_HPP
#define PARTICLE_HPP

class Particle: public Object {
public:
	Particle() :Object() {}
	~Particle() = default;
};

#endif