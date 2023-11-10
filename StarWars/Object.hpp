#include "Vec2.hpp"

#ifndef OBJECT_HPP
#define OBJECT_HPP

enum class ObjectType {
	OBJECT, 
		CHARACTER, 
			NON_PLAYER_CHARACTER, 
				ENEMY_NPC, FRIENDLY_NPC, 
			PLAYER_CHARACTER,
		DROPPED_ITEM, 
			DROPPED_SPECIAL_ITEM, DROPPED_WEAPON, 
		PARTICLE, 
		WALL
};

class Object {
public:
	Object();
	Object(bool, Vec2);
	virtual ~Object() = default;
	Vec2& GetCoord();
protected:
	bool isFixed;
	Vec2 coord;
	const ObjectType objectType = ObjectType::OBJECT;
};

#endif