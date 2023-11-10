#include "DroppedItem.hpp"

#ifndef DROPPED_SPECIAL_ITEM_HPP
#define DROPPED_SPECIAL_ITEM_HPP

class DroppedSpecialItem : public DroppedItem {
public:
	DroppedSpecialItem();
	~DroppedSpecialItem() = default;
	void useItem(Object* itemuser);
private:
	int itemType;
};

#endif