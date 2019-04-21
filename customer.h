#ifndef CUSTOMER_H

#define CUSTOMER_H

#include <iostream>
#include <string>
#include <vector>

#include "grocery.h"

using namespace std;

class customer
{
    private:
    
    string name;
    double time;
    grocery *item;

    public:

    customer();
    void read();
};

#endif