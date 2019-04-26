#ifndef GENERATE_H

#define GENERATE_H

#include <stdlib.h>
#include <time.h>

#include <string>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

vector <string> generate(int cnt);

string generate_name(int len);

void generate_customer(string filename);

#endif