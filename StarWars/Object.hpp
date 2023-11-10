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
	Vec2& GetSpeed();
	void SetCoord(const Vec2 & c);
	void SetNextCoord(const Vec2& c);
	void SetSpeed(const Vec2& s);
	bool isCollisionWith(const Object& obj);
	ObjectType getObjectType();
	bool isCharacterType();
	bool isItemType();
	int getCollisionPriority();
protected:
	bool isFixed;
	ObjectType objectType = ObjectType::OBJECT;
	Vec2 coord;
	Vec2 nextCoord;
	Vec2 speed;
};

#endif