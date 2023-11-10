#include "DroppedItem.hpp"

#ifndef DROPPED_WEAPON_HPP
#define DROPPED_WEAPON_HPP

class DroppedWeapon : DroppedItem {
public:
	DroppedWeapon();
	~DroppedWeapon() = default;
	void useItem(Object* itemuser);
private:
	int weaponType;
};

#endif