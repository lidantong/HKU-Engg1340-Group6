#ifndef CALCULATE_H

#define CALCULATE_H

// general method to calculate the maximum profit and relating counter numbers
pair <int, double> get_max(int max_counter, double counter_cost, double time_limit, int customer_cnt, const vector <customer> &c);

// calculate the revenue of a given amount of counter
double process(double time_limit, int counter_cnt, int customer_cnt, vector <customer> c);

#endif