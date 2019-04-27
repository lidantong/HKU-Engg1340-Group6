#include "test.h"

void print (vector <customer> c)
{
	cout << "time value\n"; 
	for (vector <customer> :: iterator i = c.begin(); i != c.end(); i++)
		cout << i->t << " " << i->val << endl;
}
