#include "Particle.hpp"

Particle::Particle() :Object() {
	objectType = ObjectType::PARTICLE;
	damage = 1;
}
void Particle::setDamage(const int d) {
	damage = d;
}

int Particle::getDamage() {
	return damage;
}