#ifndef GROCERY_H

#define GROCERY_H


class grocery;
// /////////////////////////////////////////////////////////////////////////////////////////////

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
      grocery(istringstream *p_info_string);

};


grocery :: grocery(istringstream *p_info_string)
{
	*p_info_string >> name >> val >> t >> cnt;
}
// /////////////////////////////////////////////////////////////////////////////////////////////

#endif