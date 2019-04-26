#include "grocery.h"
#include <iostream>
#include <sstream>
#include <string>

using namespace std;


grocery :: grocery()
{
    cnt = 0;
    t = val = 0;
    name = "";
}

grocery :: grocery(istringstream *p_info_string)
{
	*p_info_string >> name >> val >> t >> cnt;
}

