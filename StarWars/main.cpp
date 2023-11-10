#include "includes.hpp"

#include "EnemyNPC.hpp"
#include "FriendlyNPC.hpp"
#include "NonPlayerCharacter.hpp"
#include "PlayerCharacter.hpp"
#include "Character.hpp"
#include "DroppedItem.hpp"
#include "DroppedSpecialItem.hpp"
#include "DroppedWeapon.hpp"
#include "Object.hpp"
#include "Particle.hpp"
#include "Wall.hpp"

#include "FrameManager.hpp"

ObjectType typeDetect(Object* obj)
{
	if (auto character = dynamic_cast<Character*>(obj))
	{
		if (auto nonPlayableCharacter = dynamic_cast<NonPlayerCharacter*>(character))
		{
			if (auto enemyNPC = dynamic_cast<EnemyNPC*>(nonPlayableCharacter))
			{
				return ObjectType::ENEMY_NPC;
			}

			if (auto friendlyNPC = dynamic_cast<FriendlyNPC*>(nonPlayableCharacter))
			{
				return ObjectType::FRIENDLY_NPC;
			}

			return ObjectType::NON_PLAYER_CHARACTER;
		}

		if (auto playerCharacter = dynamic_cast<PlayerCharacter*>(character))
		{
			return ObjectType::PLAYER_CHARACTER;
		}

		return ObjectType::CHARACTER;
	}

	if (auto droppedItem = dynamic_cast<DroppedItem*>(obj))
	{
		if (auto droppedSpecialItem = dynamic_cast<DroppedSpecialItem*>(obj))
		{
			return ObjectType::DROPPED_SPECIAL_ITEM;
		}

		if (auto droppedWeapon = dynamic_cast<DroppedWeapon*>(obj))
		{
			return ObjectType::DROPPED_WEAPON;
		}

		return ObjectType::DROPPED_ITEM;
	}

	if (auto wall = dynamic_cast<Wall*>(obj))
	{
		return ObjectType::WALL;
	}

	if (auto particle = dynamic_cast<Particle*>(obj))
	{
		return ObjectType::PARTICLE;
	}

	return ObjectType::OBJECT;
}

int main()
{
	double player_y = 0;
	double player_acc = -9.8;
	double player_vel = 0;
	FrameManager frameManager;

	frameManager.InitFrame();

	while (1)
	{
		if (_kbhit())
		{
			while(_kbhit())
				_getch();

			player_vel += 10;
		}

		if (player_y >= 0)
		{
			player_vel += player_acc * 0.1;
		}

		else
		{
			player_vel = 0;
			player_y = 0;
		}

		player_y += player_vel;

		COORD c = { 1, static_cast<short>((200 - player_y) / 10)};

		frameManager.SetCursorPosition(c);

		frameManager.Print("asdf");
		frameManager.UpdateFrame();

		Sleep(100);
	}
}