#ifndef DEAL_H_
#define DEAL_H_

#include <list>
#include <iostream>
#include "BasketItem.h"

using namespace std;

class Deal {
protected:
	double discount;

public:
	double getDiscount();
	virtual string getName() { return ""; };
	virtual void calculateDiscount(list<BasketItem>& items) {};

};



#endif /* DEAL_H_ */
