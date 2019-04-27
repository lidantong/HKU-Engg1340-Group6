#ifndef INTERFACE_H

#define INTERFACE_H

#include <iostream>
#include <fstream>
#include "customer.h"
#include "grocery.h"
using namespace std;

void add_a_customer (vector<customer>&);
void print_logo ();
void print_man ();
void print_env (int, int, double, double);
void update_env (int &, int &, double &, double &);
void print_result (int, double);
void autofill (vector<customer> &, vector<string>);
int clear();

#endif
