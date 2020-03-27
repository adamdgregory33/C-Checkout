#ifndef DEAL3FOR2_H_
#define DEAL3FOR2_H_

#include "Deal.h"

class Deal3For2 : public Deal {

private:
	static string name;

public:
	Deal3For2() { discount = 0; };

	void calculateDiscount(list<BasketItem>& items);
	string getName();

};

#endif /* DEAL3FOR2_H_ */
