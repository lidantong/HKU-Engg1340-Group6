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
	val = t = 0;
	items = {};
}

bool operator < (const customer &a, const customer &b)
{
	return a.t > b.t;
}

void customer::read (string info_string_total)
{
	istringstream info_s_string (info_string_total);
	string info, tem;
	int count = 0;
	while (info_s_string >> info) {
		++count;
		tem += (info + ' ');

		// process the info string at a step of 4
		if (count == 4) {
			count = 0;
			istringstream info_s (tem);
			grocery item(&info_s);
			items.push_back(item);
			tem = "";
		}
		
	}
    for (vector <grocery> :: iterator i = items.begin(); i != items.end(); i++)
        t += i->t * i->cnt,
        val += i->val * i->cnt;
}

// /////////////////////////////////////////////////////////////////////////////////////////////
