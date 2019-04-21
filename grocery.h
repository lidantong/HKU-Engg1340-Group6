#ifndef GROCERY_H

#define GROCERY_H

pair <int, int> point;

#include <iostream>
#include <string>

using namespace std;

/***************************************************

   Class grocery

***************************************************/

typedef class grocery
{
private:

/***************************************************

   name: the name of each grocery
   price: the price of a single item
   time: time needed to produce a single purchase
   count: number of groceries purchased

***************************************************/

int count;
double time;
double price;
string name;

public:

/***************************************************

   Initializing grocery

***************************************************/

grocery()
{
	count = 0;
	time = price = 0;
	name = "";
}

/***************************************************

   read(): read parameters

***************************************************/

void readFromFile(string);
void readFromUser();

} g;

#endif