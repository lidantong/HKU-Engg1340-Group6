#ifndef CUSTOMER_H

#define CUSTOMER_H

class customer;
bool cmp(const customer *&a, const customer *&b);

// /////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "grocery.h"
#include "customer.h"

using namespace std;

class customer
{
private:

string name;
double time;
vector<grocery> items_vec;

public:
void read(vector<istringstream>);
friend bool cmp(const customer *&a, const customer *&b);
customer();
};

customer :: customer()
{
	name.clear();
	time = 0;
	items_vec = {};
}

bool cmp(const customer *&a, const customer *&b)
{
	return a->time < b->time;
}

void customer::read (vector<istringstream> info_string_vec) {
	vector<grocery> items;
	for (auto &info_string: info_string_vec) {
		grocery item(&info_string);
		items.push_back(item);
	}
	items_vec = items;
}

// /////////////////////////////////////////////////////////////////////////////////////////////

#endif