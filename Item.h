#ifndef ITEM_H_
#define ITEM_H_

#include <iostream>

using namespace std;

class Item {
protected:

	int id;
	string name;
	double price;
	string set;

public:
	Item() {};
	Item(int id, string name, double price, string set) : id(id), name(name), price(price), set(set) {};

	bool operator <(const Item& itemObj) const;//to override comparator for sorting, based on ID
	bool operator ==(const Item& itemObj) const;//to override comparator for sorting, based on ID
	int getId();
	double getPrice();
	string getName();
	string getSet();
	string toString();
};

#endif /* ITEM_H_ */