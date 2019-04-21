#include "grocery.h"

grocery :: grocery()
{
        cnt = 0;
        t = val = 0;
        name = "";
}

void grocery :: read()
{
    cin >> name >> cnt >> t >> val;
}