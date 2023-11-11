#include "Character.hpp"

Character::Character() : Object() {
	weapon_id = 0;
	health = 100;
	buff_timer = 0;
	speed = 1;
	objectType = ObjectType::CHARACTER;
}


void Character::setWeapon(int w_id) {
	weapon_id = w_id;
}


void Character::setHealth(const int h) {
	health = h;
}

void Character::addHealth(const int h) {
	health += h;
}

void Character::giveDamage(const int d) {
	health -= d;
}

int Character::getWeapon() {
	return weapon_id;
}
void Character::setBuffTimer(const int t) {
	buff_timer = t;
}

int  Character::getBuffTimer() {
	return buff_timer;
}