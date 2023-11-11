#include "DroppedItem.hpp"
#include "Character.hpp"
#ifndef DROPPED_WEAPON_HPP
#define DROPPED_WEAPON_HPP

class DroppedWeapon : DroppedItem {
public:
	DroppedWeapon();
	DroppedWeapon(int w_id);
	~DroppedWeapon() = default;
	void useItem(Object* itemuser);
private:
	int weapon_id;
	const int TOTAL_WEAPON = 3;// 0 : 주먹, 1 : 권총, 2 : 돌격소총
};

#endif