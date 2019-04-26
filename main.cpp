#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include "interface.h"
#include "calculate.h"

#include <stdio.h>


int main()
{
    // Print our logo to the screen
	print_logo();
    // Print the manual page for the user's reference
	print_man();
    // Waiting for the user to input command
	string man;
    cout << "What would you like to do?" << endl << "Your input: ";
	cin >> man;
    // Initialising the environment
    int max_counter = 50, customer_cnt = 0;
    double cost = 20, time_limit = 900;
    // Creating the customer vector which is temporarily empty
    vector<customer> cus;
    // Keep adding new customers till
	while (man != "DONE") {
        if (man == "ADD") {
            //
            cout << "*********************ADDING A NEW CUSTOMER************************" << endl;
            add_a_customer(cus);
            customer_cnt += 1;
            print_man();
        }
		else cout << "Please input correctly!" << endl << endl; 

        cout << "Your next input: ";
        cin >> man;
	}
    // Customer array is successfully initialised
    cout << "Congratulations! Customer array is successfully initialised!" << endl;

    print_env(max_counter, customer_cnt, cost, time_limit);

    cout << "Are you sure about the circumstance? (CAREFUL: Wrong circumstance may result in unreliable result.)" << endl << "'yes' / 'no' : ";

    // Take user input to decide whether to change the circumstance
    string update;
    cin >> update;

    while (update == "no") {
        update_env(max_counter, customer_cnt, cost, time_limit);
        cout << "Are you sure about the circumstance? (CAREFUL: Wrong circumstance may result in unreliable result.)" << endl << "'yes' / 'no' : ";
        cin >> update;
    }

    cout << "Environment is all set, we are processing..." << endl;

    pair<int, double> result = get_max(max_counter, cost, time_limit, customer_cnt, cus);

    print_result(result.first, result.second);

}

