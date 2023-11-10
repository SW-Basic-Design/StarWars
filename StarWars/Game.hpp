#include "includes.hpp"

#include "EnemyNPC.hpp"
#include "FriendlyNPC.hpp"
#include "NonPlayerCharacter.hpp"
#include "PlayerCharacter.hpp"
#include "Character.hpp"
#include "Object.hpp"
#include "Particle.hpp"
#include "Wall.hpp"

#ifndef GAME_HPP
#define GAME_HPP

class Game {
public:
	Game(bool isGameOver) :isGameOver(isGameOver) {}
	void UpdateObjects();
private:
	bool isGameOver;
	std::vector<Object> objects;
};

#endif