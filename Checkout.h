#ifndef CHECKOUT_H_
#define CHECKOUT_H_
#include <iostream>
#include <list>
#include <sstream>

#include "BasketItem.h"
#include "Deal.h"

using namespace std;

class Checkout {

private:
	static int const MAXITEMS = 8; //hold maximum items stored in store
	static int count;//number of tills open
	static Item stockList[MAXITEMS];//the various items in the store

	int checkoutId;//autoIncrements based on number of open checkouts.
	list<BasketItem> basketItems;
	list<Deal*> deals;
	stringstream receipt;
	double currentTotal;
	double discountValue;

	void initialiseDeals();
	void addItems();
	void generateReceipt();
	void sortItemList();
	void applyDiscounts();
	void displayItems();

	Item findItem(int id);


public:
	Checkout() {
		cout << "Opening Checkout..." << endl;
		checkoutId = ++count;
		cout << "Checkout >" << checkoutId << "< is now open." << endl<<endl;
		currentTotal = 0;
		discountValue = 0;
	};
	~Checkout() {
		cout << endl << "Closing Checkout >" << checkoutId << "< " << endl;
		count--;
		cout << "Checkout closed." << endl;

	};

	void nextCustomer();

};

#endif /* CHECKOUT_H_ */
