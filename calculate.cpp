#include "customer.h"
#include "calculate.h"

#include <algorithm>
#include <queue>

using namespace std;

priority_queue <customer> pq;

pair <int, double> get_max(int max_counter, double counter_cost, double time_limit, int customer_cnt, const vector <customer> &c)
{
    pair <int, double> ans(-1e18, 0);
    for (int i = 0; i < max_counter; i++)
    {
        //calculate answer for each counter and update final answer
        double tmp = process(time_limit, i, customer_cnt, c) - counter_cost * i;
        if (tmp > ans.second)
            ans.first = i,
            ans.second = tmp;
    }
    return ans;
}

double process(double time_limit, int counter_cnt, int customer_cnt, vector <customer> c)
{
    // clean the heap before each process
    while (!pq.empty())
        pq.pop();
    // the size of the heap should be no lareger than counter_cnt
    for (int i = 0; i < counter_cnt; i++)
        pq.push(c[i]);
    double time_lable = 0, ans = 0;
    int lable = counter_cnt, max_lable = c.size();;
    while (time_lable <= time_limit )
    {
        // the customer which takes least time finished his or her purchase
        customer x = pq.top();
        pq.pop();
        // current time equals to the time last customer takes
        time_lable = x.t;
        ans += x.val;
        //add a new customer to the counter if applicable
        if (lable < max_lable)
        {
            c[lable].t = time_lable;
            pq.push(c[lable++]);
        }
    }
    return ans;
}