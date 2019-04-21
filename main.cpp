#include <iostream>
#include <string>
#include <vector>
#include "interface.h"
#include "calculate.h"

#include <stdio.h>


int main()
{
	print_logo();

	print_man();

	string man;
	cin >> man;

    int max_counter = 50, customer_cnt = 0;
    double cost = 20, time_limit = 900;
    vector<customer> cus;

	while (man != "DONE") {
        if (man == "ADD") {
            add_a_customer(cus);
            customer_cnt += 1;
        }
		else cout << "Please input correctly " << endl << endl; 
	}

    print_env(max_counter, customer_cnt, cost, time_limit);

    cout << "ok?" << endl;

    string update;
    cin >> update;

    while (update == "yes") {
        update_env(max_counter, customer_cnt, cost, time_limit);
        cout << "ok?" << endl;
        cin >> update;
    }

    int best_no_of_counter = get_max(max_counter, cost, time_limit, customer_cnt, cus);

    double revenue = process(time_limit, best_no_of_counter, customer_cnt, cus);

    print_result(max_counter, revenue);

}