#include <iterator>
#include <iostream>
#include <math.h>

#include "DealSameSet.h"

string DealSameSet::name = "Cheapest item in set free";

void DealSameSet::calculateDiscount(list<BasketItem>& items) {

	items.sort([](BasketItem& item1, BasketItem& item2)
		{
			if (item1.getSet() == item2.getSet()) {
				return item1.getPrice() > item2.getPrice();
			}
			return item1.getSet() < item2.getSet();


		});//orders in price order, within sets

	list<BasketItem>::iterator i = items.begin();

	list<BasketItem> tempList;
	list<BasketItem> newList;

	BasketItem tempItem;

	bool firstItem = true;
	bool finished = false;

	unsigned int loopCount = 1;

	while (!finished) {
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

			if (!finished && (tempItem.getSet() == i->getSet()) && !(i->getDealUsed())) {
				tempList.push_front(*i);


			}
			else if (!finished && (tempItem.getSet() == i->getSet()) && (i->getDealUsed())) {
				newList.push_front(*i);


			}
			else if (finished || (tempItem.getSet() != i->getSet())) {
				//at this point, all of the items with the same ID, and without used deals are in templist
				//we calculate the discount from this list by iterating through,

				if (tempList.size() < 3) {//cannot be a valid part of the 3 for 2 deal if there are less than 3 items

					for (auto& j : tempList) {
						newList.push_front(j);
					}
					tempList.clear();



				}
				else {

					int numberOfDeals = floor(tempList.size() / 3);//purchase 3, get cheapest free
					//int remainder = tempList.size() %3;

					int k = 0;

					list<BasketItem>::iterator z;

					for (z = tempList.begin(); k < numberOfDeals; k++, z++) {

						discount += z->getPrice();//adds lowest value item in set to discount
					}

					k = 0;

					for (z = tempList.begin(); z != tempList.end(); z++, k++) {
						//re-adding the cheapest items in the list with deal now used, cheapest used to maximise potential customer savings
						if (k < (numberOfDeals * 3)) {
							z->setDealUsed(true);
						}
						newList.push_front(*z);

					}

					tempList.clear();

				}

				if (!finished) {
					if (!i->getDealUsed()) {

						tempList.push_front(*i);
						tempItem = *i;//updates the temporary item comparing to current item with differnet set

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


	if (!tempList.empty()) {//flush temporary list into new list
		for (auto& j : tempList) {
			newList.push_front(j);
		}
	}

	items = newList;

}

string DealSameSet::getName() {
	return name;
}
