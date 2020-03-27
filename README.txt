Supermarket Checkout:

Working in Visual Studio 2019 on Windows 10.

Usage:
-import the project using VS2019, build project debug configuration
-Run using debug configuration / windows debug logger, or using EXE in debug folder

Assumptions/Considerations:

-Items are scanned by scanner, giving the Item IDs, hence input is via Item ID. 
-Items can only have one deal applied to them at any instant. 
-Deals maximise user discount (hence 3 for 2 is applied first, as this will always give the biggest discount for the user)
-Overall discount only considered, ie no specific breakdown of discounts. This could be achieved with an extra field on BasketItem, indicating what price will be paid by the customer for a given item.


Layout:

Store.cpp - Holds the main method, which can be used to start up Checkout objects

Checkout.cpp - Holds a stocklist and other various member variables. Stock list is held in an array as new items being added to existing inventory list potentially rare. Multiple checkouts can be opened, and they share a stocklist, autoincrement in their ID.

Item - stores items in stocklist

BasketItem - extends Item to contain field bool dealUsed, for whether an item in the basket has been used in a deal already

Deal - subclassed by Deal3For2 and DealSameSet, this super class allows interchanging of the applyDiscount method depending on a specific deal implementation. Allows future deals to be added with ease

Further Considerations:

- After implementing Deal classes working properly, the implementation could remove items that have already been used in a deal prior to processing to improve readability of code
- Writing to a file output/ reading from a file input/database for the stock list could be implemented
- Flesh out Store.cpp to run until user inputs they are finished with customers
- GUI
- Unit testing of deal classes to ensure functionality across wide range of inputs. Having completed the project on Eclipse initially, I attempted to move files over to Visual studio to use in built unit testing features, but this did not work out as and my lack of knowledge with regards to C++ development meant that learning the intricacies of unit testing here was taking too long

