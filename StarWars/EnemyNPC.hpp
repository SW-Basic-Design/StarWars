#include "NonPlayerCharacter.hpp"

#ifndef ENEMY_NPC_HPP
#define ENEMY_NPC_HPP

class EnemyNPC : public NonPlayerCharacter {
public:
	EnemyNPC() : NonPlayerCharacter() { }
	~EnemyNPC() = default;
private:
};

#endif