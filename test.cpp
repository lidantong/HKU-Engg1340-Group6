#include "test.h"

void print (vector <customer> c)
{
	for (vector <customer> :: iterator i = c.begin(); i != c.end(); i++)
		cout << i->t << " " << i->val << endl;
}
