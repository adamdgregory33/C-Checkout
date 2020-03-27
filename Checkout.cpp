#include <iostream>
#include <limits>
#include <iterator>
#include <stdexcept>
#include <stdio.h>
#include <iostream>
#include <io.h>
#include <fcntl.h>

#include "Checkout.h"
#include "Deal.h"
#include "Deal3For2.h"
#include "DealSameSet.h"
#include "Item.h"

using namespace std;

int Checkout::count = 0;

Item Checkout::stockList[] = {
		Item(1,"Apple",0.1,"set1"),
		Item(2,"Orange",0.05,"set1"),
		Item(3,"Banana",0.2,"set1"),
		Item(4,"Pear",0.3,"set2"),
		Item(5,"Bread",0.4,"set2"),
		Item(6,"Cheese",1.5,"set2"),
		Item(7,"Chocolate",1,"set3"),
		Item(8,"Meat Selection",5,"set3") };


void Checkout::nextCustomer() {
	//acts as the functioning of a till with a new customer, addining items and creating a receipt

	addItems();

	generateReceipt();

	cout << receipt.str();

}


void Checkout::addItems() {
	//mimics scanning items at supermarket 1 by 1

	bool finished = false;
	cout << "Please scan your items (enter item ID), enter -1 to finish: " << endl;

	while (!finished) {


		int newItemId = 0;

		while (cout << "Enter item ID: " << flush && !(cin >> newItemId)) {

			cin.clear(); //clear bad input flag
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //discard input
			cout << "Item Id is an integer, please try again" << endl;
		}

		if (newItemId == -1) {

			finished = true;

		}
		else {
			try {

				BasketItem temp;//method throws exception if invalid ID is entered
				temp = BasketItem(findItem(newItemId));

				basketItems.push_front(temp);
				cout << "Added: " << temp.toString() << endl;

			}
			catch (const std::exception & e) {

				cout << "Item ID not valid, please try again" << endl;

			}

		}
	}
	basketItems.sort();

}


void Checkout::initialiseDeals() {
	//initialise the deals. Deals stored in a list to add more in future

	Deal3For2 deal1;//derived class
	DealSameSet deal2;

	Deal* pDeal1 = &deal1;//base class pointer
	Deal* pDeal2 = &deal2;

	deals.push_back(pDeal1);
	deals.push_back(pDeal2);


	applyDiscounts();

}

void Checkout::applyDiscounts() {
	//loops through the discounts initialised and applies them to the basket of goods

	receipt << "Deal Discounts:\n";

	list<Deal*>::iterator it;

	for (it = deals.begin(); it != deals.end(); it++) {

		if (basketItems.size() != 0) {
			(*it)->calculateDiscount(basketItems);

			double dealDiscount = 0;

			dealDiscount += (*it)->getDiscount();

			if (dealDiscount != 0) {

				discountValue += dealDiscount;

				char buffer[100];
				sprintf_s(buffer, "%0.2f", dealDiscount);
				receipt << (*it)->getName() << ": -"<< (char)156 << buffer << "\n";

			}

		}

	}
	char buffer[100];
	sprintf_s(buffer, "%0.2f", (currentTotal - discountValue));

	receipt << "-------------------------------------\n"
		<< "Total:      "<< (char)156 << buffer << "\n"
		<< "=====================================\n";

}


void Checkout::generateReceipt() {//formats the output of the receiept

	cout << endl << "Generating Receipt..." << endl << endl;

	receipt << "-------------------------------------\n"
		<< "=========Final Bill of Goods=========\n"
		<< "-------------------------------------\n";

	for (auto& i : basketItems) {

		receipt << i.toString() << "\n";
		currentTotal += i.getPrice();

	}

	char buffer[100];
	sprintf_s(buffer, "%.02f", currentTotal);
	receipt << "-------------------------------------\n"
		<< "Subtotal:   "<< (char)156 << buffer << "\n"
		<< "-------------------------------------\n";

	initialiseDeals();//initialises the discounts calculation

}

Item Checkout::findItem(int id) {

	return stockList[id - 1];

	throw std::invalid_argument("Id does not pertain to a valid item, try again");
}

void Checkout::displayItems() {

	for (auto& j : basketItems) {
		cout << j.toString() << endl;
	}
}
