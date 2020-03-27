#ifndef BASKETITEM_H_
#define BASKETITEM_H_

#include "Item.h"

class BasketItem : public Item {
private:
	bool dealUsed;

public:
	BasketItem() { dealUsed = false; };
	BasketItem(Item item) {

		name = item.getName();
		price = item.getPrice();
		set = item.getSet();
		id = item.getId();
		dealUsed = false;

	};
	void setDealUsed(bool used);
	bool getDealUsed();

};

#endif /* BASKETITEM_H_ */
