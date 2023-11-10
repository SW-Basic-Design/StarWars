#include "Character.hpp"

Character::Character() : Object() {
	objectType = ObjectType::CHARACTER;
}

void Character::setHealth(const int h) {
	health = h;
}

void Character::giveDamage(const int d) {
	health -= d;
}