#include "customer.h"

customer :: customer()
{
    name.clear();
    time = 0;
    item = NULL;
}

void customer :: read()
{
    int cnt;
    cin >> name >> cnt;
    item = new grocery[cnt]();
    for (int i = 0; i < cnt; i++)
        item[i]->read();
}