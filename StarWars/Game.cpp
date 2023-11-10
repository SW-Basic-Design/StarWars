#include "Game.hpp"

void Game::UpdateObjects()
{
	for (int i = 0; i < objects.size(); i++) {
		for (int j = 0; j < objects.size(); j++) {
			if (i != j && objects[i]->isCollisionWith(*objects[j])) {
				if (objects[i]->getCollisionPriority() > objects[j]->getCollisionPriority()) {//현재 오브젝트의 우선순위 등급이 j번째 오브젝트의 우선순위 등급보다 낮다면 (1이 가장 높음))
					objects[i]->SetNextCoord(objects[i]->GetCoord());//현재 오브젝트의 다음 위치를 기존 위치로 변경
					objects[i]->SetSpeed(Vec2(0,0));// 속도를 0으로 초기화
				}
				
				if (objects[i]->getObjectType() == ObjectType::PARTICLE) {// 총알일 경우
					delete objects[i];//해당 오브젝트 삭제 
					i--;
					continue;
				}

				if (objects[i]->isCharacterType() && objects[j]->getObjectType() == ObjectType::PARTICLE) {// == isPlayerHit
					((Character*)objects[i])->giveDamage(((Particle*)objects[j])->getDamage());//데미지를 입힘. UpdatePlayerState의 일부 기능
					continue;
				}

				if (objects[i]->isCharacterType() && objects[j]->isItemType()) {// == CheckItemObtained
					((DroppedItem*)objects[j])->useItem(objects[i]);//아이템 사용. UpdatePlayerState의 일부 기능도 포함됨.
					continue;
				}

			}
		}
	}
	
}