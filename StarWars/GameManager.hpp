#include "FrameManager.hpp"

#ifndef GAME_MANAGER_HPP
#define GAME_MANAGER_HPP

class GameManager {
public:
	GameManager();
	void startGame();
private:
	FrameManager frameManager;
};

#endif