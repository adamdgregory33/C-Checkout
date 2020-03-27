#include <iterator>
#include <iostream>
#include <math.h>

#include "Deal3For2.h"

string Deal3For2::name = "Buy 3 identical, get one free";

void Deal3For2::calculateDiscount(list<BasketItem>& items) {
	
	items.sort();//orders from id smallest to largest ID

	list<BasketItem>::iterator i = items.begin();

	list<BasketItem> tempList;
	list<BasketItem> newList;

	BasketItem tempItem;

	bool firstItem = true;
	bool finished = false;

	unsigned int loopCount = 1;

	while (!finished) {//loop needs to run once after pointer has reach end of list

		finished = (i == items.end());

		if (firstItem && !finished) {

			tempItem = *i;

			if (tempItem.getDealUsed()) {

				newList.push_front(tempItem);

			}
			else {

				tempList.push_front(tempItem);
				firstItem = false;
			}

		}
		else {//continues through list till it finds item not used in a deal
		   //this section begins a loop after tempItem has been found

			if (!finished && tempItem.getId() == i->getId() && !(i->getDealUsed())) {

				tempList.push_front(*i);

			}
			else if (!finished && tempItem.getId() == i->getId() && (i->getDealUsed())) {

				newList.push_front(*i);

			}
			else if (finished || (tempItem.getId() != i->getId())) {
				//at this point, all of the items with the same ID, and without used deals are in templist
				//we calculate the discount from this list by iterating through,

				if (tempList.size() < 3) {//cannot be a valid part of the 3 for 2 deal if there are less than 3 items

					for (auto& j : tempList) {
						newList.push_front(j);
					}
					tempList.clear();


				}
				else {

					int numberOfDeals = floor(tempList.size() / 3);
					int remainder = tempList.size() % 3;

					discount += numberOfDeals * tempItem.getPrice();

					for (int z = 0; z < (remainder); z++) {
						newList.push_front(tempItem);
					}

					tempItem.setDealUsed(true);

					for (int z = 0; z < (numberOfDeals * 3); z++) {
						newList.push_front(tempItem);
					}

					tempList.clear();
				}

				if (!finished) {
					if (!i->getDealUsed()) {
						tempList.push_front(*i);
						tempItem = *i;

					}
					else {
						newList.push_front(*i);
						firstItem = true;//reset the logic to search for an item with a non used deal

					}
				}

			}

		}

		if (loopCount <= items.size()) {
			i++;
		}
		loopCount++;

	}


	if (!tempList.empty()) {
		for (auto& j : tempList) {
			newList.push_front(j);
		}
	}

	items = newList;
}

string Deal3For2::getName() {
	return name;
}
