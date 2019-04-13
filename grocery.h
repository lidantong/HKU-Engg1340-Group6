#ifndef GROCERY_H

#define GROCERY_H

pair <int, int> point
 
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

    grocery()
    {
        cnt = 0;
        t = val = 0;
        name = "";
    }

/***************************************************

read(): read parameters

***************************************************/

    void read()
    {
        cin >> name >> cnt >> t >> val;
    }

} g;

#endif