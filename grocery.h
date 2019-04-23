#ifndef GROCERY_H

#define GROCERY_H


class grocery;
// /////////////////////////////////////////////////////////////////////////////////////////////
#include "grocery.h"
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

/***************************************************

   Class grocery

***************************************************/

class grocery
{
private:

/***************************************************

   name: the name of each grocery
   val: the value of a single item
   t: time needed to produce a single purchase
   cnt: number of groceries purchased

***************************************************/

int cnt;
double t;
double val;
string name;

public:

/***************************************************

   Initializing grocery

***************************************************/
grocery(istringstream *info_string);
};


grocery :: grocery(istringstream *info_string)
{
	cnt = 0;
	t = val = 0;
	name.clear();
	*info_string >> name >> val >> t >> cnt;

}
// /////////////////////////////////////////////////////////////////////////////////////////////

#endif