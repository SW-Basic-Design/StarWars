#include "Game.hpp"

void Game::UpdateObjects()
{
	for (int i = 0; i < objects.size(); i++) {
		for (int j = 0; j < objects.size(); j++) {
			if (i != j && objects[i]->isCollisionWith(*objects[j])) {
				if (objects[i]->getCollisionPriority() > objects[j]->getCollisionPriority()) {//���� ������Ʈ�� �켱���� ����� j��° ������Ʈ�� �켱���� ��޺��� ���ٸ� (1�� ���� ����))
					objects[i]->SetNextCoord(objects[i]->GetCoord());//���� ������Ʈ�� ���� ��ġ�� ���� ��ġ�� ����
					objects[i]->SetSpeed(Vec2(0,0));// �ӵ��� 0���� �ʱ�ȭ
				}

				if(objects[i]->getObjectType() == ObjectType::PARTICLE) {
					if(objects[j]->isCharacterType()) {
						((Character*)objects[j])->giveDamage(((Particle*)objects[i])->getDamage());//�������� ����. UpdatePlayerState�� �Ϻ� ���
						delete objects[i];//�Ѿ� ������Ʈ ���� 
						objects.erase(objects.begin() + i);
						i--;
						break;
					}
					if(objects[j]->getObjectType() == ObjectType::WALL) {
						delete objects[i];//�Ѿ� ������Ʈ ���� 
						objects.erase(objects.begin() + i);
						i--;
						break;
					}
				}
				else if(objects[j]->getObjectType() == ObjectType::PARTICLE) {
					if(objects[i]->isCharacterType()) {
						((Character*)objects[i])->giveDamage(((Particle*)objects[j])->getDamage());//�������� ����. UpdatePlayerState�� �Ϻ� ���
						delete objects[j];//�Ѿ� ������Ʈ ���� 
						objects.erase(objects.begin() + j);
						if(i > j) {
							i--;
						}
						j--;
						continue;
					}
					if(objects[j]->getObjectType() == ObjectType::WALL) {
						delete objects[j];//�Ѿ� ������Ʈ ���� 
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
						((DroppedItem*)objects[j])->useItem(objects[i]);//������ ���. UpdatePlayerState�� �Ϻ� ���
						delete objects[j];//������ ������Ʈ ���� 
						objects.erase(objects.begin() + j);
						if(i > j) {
							i--;
						}
						j--;
						continue;
					}
					if (objects[j]->isCharacterType() && objects[i]->isItemType()) {// == CheckItemObtained
						((DroppedItem*)objects[i])->useItem(objects[j]);//������ ���. UpdatePlayerState�� �Ϻ� ���
						delete objects[i];//������ ������Ʈ ���� 
						objects.erase(objects.begin() + i);
						i--;
						break;
					}
				}
			}
		}
	}
}