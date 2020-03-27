#include <sstream>
#include "Item.h"


string Item::toString() {

	stringstream ss;

	char buffer[100];
	sprintf_s(buffer, "%0.2f", price);

	ss << name << " ----- "<< (char)156 << buffer;
	return ss.str();

}

bool Item::operator <(const Item& itemObj) const
{
	return id < itemObj.id;
}

bool Item::operator ==(const Item& itemObj) const {
	return id == itemObj.id;
}

double Item::getPrice() {
	return price;
}


string Item::getName() {
	return name;
}

int Item::getId() {
	return id;
}

string Item::getSet() {
	return set;
}
