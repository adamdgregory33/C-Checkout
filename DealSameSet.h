#ifndef DEALSAMESET_H_
#define DEALSAMESET_H_

#include "Deal.h"

class DealSameSet : public Deal {

private:
	static string name;

public:

	DealSameSet() { discount = 0; };

	void calculateDiscount(list<BasketItem>& items);
	string getName();

};
#endif /* DEALSAMESET_H_ */
