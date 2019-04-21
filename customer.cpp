#include <iostream>
#include <string>
#include <vector>

#include "grocery.h"
#include "customer.h"

using namespace std;

class customer
{
    private:
    
    string name;
    double time;
    grocery *item;

    public:
    friend bool cmp(const customer *&a, const customer *&b);
    customer();
};

customer :: customer()
{
    name.clear();
    time = 0;
    item = NULL;
}

bool cmp(const customer *&a, const customer *&b)
{
    return a->time < b->time;
}