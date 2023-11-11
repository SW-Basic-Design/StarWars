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

				if(objects[i]->getObjectType() == ObjectType::PARTICLE) {
					if(objects[j]->isCharacterType()) {
						((Character*)objects[j])->giveDamage(((Particle*)objects[i])->getDamage());//데미지를 입힘. UpdatePlayerState의 일부 기능
						delete objects[i];//총알 오브젝트 삭제 
						objects.erase(objects.begin() + i);
						i--;
						break;
					}
					if(objects[j]->getObjectType() == ObjectType::WALL) {
						delete objects[i];//총알 오브젝트 삭제 
						objects.erase(objects.begin() + i);
						i--;
						break;
					}
				}
				else if(objects[j]->getObjectType() == ObjectType::PARTICLE) {
					if(objects[i]->isCharacterType()) {
						((Character*)objects[i])->giveDamage(((Particle*)objects[j])->getDamage());//데미지를 입힘. UpdatePlayerState의 일부 기능
						delete objects[j];//총알 오브젝트 삭제 
						objects.erase(objects.begin() + j);
						if(i > j) {
							i--;
						}
						j--;
						continue;
					}
					if(objects[j]->getObjectType() == ObjectType::WALL) {
						delete objects[j];//총알 오브젝트 삭제 
						objects.erase(objects.begin() + j);
						if(i > j) {
							i--;
						}
						j--;
						continue;
					}
				}
				else {
					if (objects[i]->isCharacterType() && objects[j]->isItemType()) {// == CheckItemObtained
						((DroppedItem*)objects[j])->useItem(objects[i]);//아이템 사용. UpdatePlayerState의 일부 기능
						delete objects[j];//아이템 오브젝트 삭제 
						objects.erase(objects.begin() + j);
						if(i > j) {
							i--;
						}
						j--;
						continue;
					}
					if (objects[j]->isCharacterType() && objects[i]->isItemType()) {// == CheckItemObtained
						((DroppedItem*)objects[i])->useItem(objects[j]);//아이템 사용. UpdatePlayerState의 일부 기능
						delete objects[i];//아이템 오브젝트 삭제 
						objects.erase(objects.begin() + i);
						i--;
						break;
					}
				}
			}
		}
	}
}