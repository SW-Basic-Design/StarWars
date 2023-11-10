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
				
				if (objects[i]->getObjectType() == ObjectType::PARTICLE) {// �Ѿ��� ���
					delete objects[i];//�ش� ������Ʈ ���� 
					i--;
					continue;
				}

				if (objects[i]->isCharacterType() && objects[j]->getObjectType() == ObjectType::PARTICLE) {// == isPlayerHit
					((Character*)objects[i])->giveDamage(((Particle*)objects[j])->getDamage());//�������� ����. UpdatePlayerState�� �Ϻ� ���
					continue;
				}

				if (objects[i]->isCharacterType() && objects[j]->isItemType()) {// == CheckItemObtained
					((DroppedItem*)objects[j])->useItem(objects[i]);//������ ���. UpdatePlayerState�� �Ϻ� ��ɵ� ���Ե�.
					continue;
				}

			}
		}
	}
	
}