#include "Object.hpp"

Object::Object() : Object(false, { 0, 0 }) {}

Object::Object(bool isFixed, Vec2 coord) : isFixed(isFixed), coord(coord) {
	speed = 0;
	nextCoord = coord;
	objectType = ObjectType::OBJECT;
}

Vec2& Object::GetCoord() {
	return this->coord;
}

Vec2& Object::GetSpeed() {
	return this->speed;
}

ObjectType Object::getObjectType() {
	return objectType;
}

void Object::SetCoord(const Vec2& c) {
	this->coord = c;
}

void Object::SetNextCoord(const Vec2& c) {
	this->nextCoord = c;
}

void Object::SetSpeed(const Vec2& s) {
	this->speed = s;
}



bool Object::isCharacterType() {
	if (this->objectType == ObjectType::ENEMY_NPC || this->objectType == ObjectType::FRIENDLY_NPC || this->objectType == ObjectType::PLAYER_CHARACTER || this->objectType == ObjectType::NON_PLAYER_CHARACTER || this->objectType == ObjectType::CHARACTER)
		return true;

	return false;
}

bool Object::isItemType() {
	if (this->objectType == ObjectType::DROPPED_ITEM || this->objectType == ObjectType::DROPPED_SPECIAL_ITEM || this->objectType == ObjectType::DROPPED_WEAPON)
		return true;

	return false;
}

int Object::getCollisionPriority() {//������Ʈ�� Type�� ���� �켱������ ��ȯ��. �켱������ 1 �� �������� �켱������ ����.
	if (this->objectType == ObjectType::WALL) {
		return 1;
	}
	else if (this->isCharacterType()) {
		return 2;
	}
	else if (this->isItemType()) {
		return 3;
	}
	else if (this->objectType == ObjectType::PARTICLE) {
		return 4;
	}
	else {
		return 0;
	}

}

bool Object::isCollisionWith(const Object& obj) {
	/*
	* this �� Character �� ���
	* �浹�� �˻��� �� 1x2 ����� ��� Ȯ��
	*/
	const int CHARSIZE_X = 1;
	const int CHARSIZE_Y = 2;

	if (this->isCharacterType()) {
		for (int y = 0; y < CHARSIZE_Y; y++) {
			for (int x = 0; x < CHARSIZE_X; x++) {
				if (this->nextCoord + Vec2(x,y) == obj.nextCoord) {
					return true;
				}
			}
		}
		return false;
	}
	
	if (this->nextCoord == obj.nextCoord) {
		return true;
	}

	return false;
}