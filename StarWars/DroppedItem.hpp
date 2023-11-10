#include "Object.hpp"

#ifndef DROPPED_ITEM_HPP
#define DROPPED_ITEM_HPP

class DroppedItem : public Object {
public:
	DroppedItem();
	~DroppedItem() = default;
	virtual void useItem(Object* itemuser) = 0;
protected :
};

#endif