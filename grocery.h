#ifndef GROCERY_H

#define GROCERY_H

#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class grocery
{
   private:

      int cnt;
      double t;
      double val;
      string name;
      friend class customer;

   public:

      grocery();
      grocery(istringstream *p_info_string);
	friend void generate_customer(string);
};

// /////////////////////////////////////////////////////////////////////////////////////////////

#endif
