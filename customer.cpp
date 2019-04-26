#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "grocery.h"
#include "customer.h"

using namespace std;

customer :: customer()
{
	name.clear();
	t = 0;
	items = {};
}

bool operator < (const customer &a, const customer &b)
{
	return a.t < b.t;
}

void customer::read (vector <istringstream> info_string_vec)
{
	// Use the istringstream vector to initialise list of grocery object and build the items vector of a customer
	for (auto &info_string: info_string_vec) {
		grocery item(&info_string);
		items.push_back(item);
	}
    for (vector <grocery> :: iterator i = items.begin(); i != items.end(); i++)
        t += i->t * i->cnt,
        val += i->val * i->cnt;
}

// /////////////////////////////////////////////////////////////////////////////////////////////