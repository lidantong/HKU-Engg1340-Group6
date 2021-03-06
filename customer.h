#ifndef CUSTOMER_H

#define CUSTOMER_H

// /////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "grocery.h"

using namespace std;

class customer
{
    private:

        string name;
        double t;
        double val;
        vector <grocery> items;

    public:
        
        void read (string  info_string_vec);
        friend bool operator < (const customer &a, const customer &b);
	    friend void print(vector <customer>);
	    friend double process(double time_limit, int counter_cnt, int customer_cnt, vector <customer> c);
        customer();
};

#endif
