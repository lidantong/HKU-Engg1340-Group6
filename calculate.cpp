#include "customer.h"
#include "calculate.h"

#include <algorithm>
#include <queue>

using namespace std;

priority_queue <customer> pq;

pair <int, double> get_max(int max_counter, double counter_cost, double time_limit, int customer_cnt, customer *c)
{
    sort(c, c + customer_cnt * sizeof(customer), cmp);
    pair <int, double> ans(-1e18, 0);
    for (int i = 0; i < max_counter; i++)
    {
        double tmp = process(time_limit, i, customer_cnt, c) - counter_cost * i;
        if (tmp > ans.second)
            ans.first = i,
            ans.second = tmp;
    }
    return ans;
}

double process(double time_limit, int counter_cnt, int customer_cnt, customer *c[])
{
    while (!pq.empty())
        pq.pop();
}