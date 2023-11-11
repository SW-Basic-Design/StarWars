#include "DroppedSpecialItem.hpp"

DroppedSpecialItem::DroppedSpecialItem()  {
	DroppedSpecialItem(0);
}

DroppedSpecialItem::DroppedSpecialItem(int i_id) : DroppedItem() {
	specialitem_id = i_id;
	objectType = ObjectType::DROPPED_SPECIAL_ITEM;
}

void DroppedSpecialItem::useItem(Object* itemuser) {
	// specialitem_id, 0 : heal, 1 : speed up, 2 : freeze
	const int PLAYER_MAX_HEALTH = 100; // 상수들은 나중에 따로 클래스로 묶어야 할듯
	switch(specialitem_id) {
		case 0 ://0 : heal 30% of max health
			((Character *)itemuser)->addHealth(PLAYER_MAX_HEALTH  * 30 / 100);
			break;
		case 1 ://1 : speed up for 10 sec
			((Character *)itemuser)->setBuffTimer(10);
			((Character *)itemuser)->SetSpeed(2);
			break;
		case 3 ://2 : freeze 를 어떻게 구현해야 할까? 다른 player에게 접근할 방법은?
			
			break;
	}



}