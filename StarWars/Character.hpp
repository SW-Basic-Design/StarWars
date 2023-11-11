#include "Object.hpp"

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

class Character : public Object {
public:
	Character();
	~Character() = default;
	void setHealth(const int h);
	void addHealth(const int h);
	void giveDamage(const int d);
	void setWeapon(const int w_id);
	int getWeapon();
	void setBuffTimer(const int t);
	int getBuffTimer();

protected:
	int speed;
	int health;
	int weapon_id;//weapon : 무기,
	int buff_timer;//버프/디버프 남은 시간
};

#endif