#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include "interface.h"
#include "calculate.h"
#include "generate.h"
#include <stdio.h>
using namespace std;

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
	double cost = 5, time_limit = 500;
	// Creating the customer vector which is temporarily empty
	vector<customer> cus;
	// Keep adding new customers till
	while (man != "DONE") {
		if (man == "ADD") {
			//
			cout << endl << "*********************ADDING A NEW CUSTOMER************************" << endl;
			bool check = add_a_customer(cus);
			customer_cnt += check;
			// print_man();
		}
		else if (man == "TEST") {
			cout << "*********************GENERATE RANDOM CUSTOMERS************************" << endl;
			cout << "How many random customers do you want to generate?" << endl;
			cout << "(int)Your number : ";
			cin >> customer_cnt;
			vector<string> names = generate(customer_cnt);
			autofill(cus, names);
		}
		else if (man == "EXIT") {
			cout << endl << endl << "Thank you for your use, see you!" << endl << endl;
			print_logo();
			exit(0);
		}
		else cout << "Please input correctly!" << endl << endl;

		print_man();
		cout << "Your next input: ";
		cin >> man;
	}
	// Customer array is successfully initialised
	cout << "Congratulations! Customer array is successfully initialised!" << endl;

	print_env(max_counter, customer_cnt, cost, time_limit);

	cout << "Are you sure about the circumstance? (CAREFUL: Wrong circumstance may result in unreliable result.)" << endl << "'YES' / 'NO' : ";

	// Take user input to decide whether to change the circumstance
	string update;
	cin >> update;

	while (update == "NO") {
		update_env(max_counter, customer_cnt, cost, time_limit);
		cout << "Are you sure about the circumstance? (CAREFUL: Wrong circumstance may result in unreliable result.)" << endl << "'YES' / 'NO' : ";
		cin >> update;
	}

	cout << endl << "Environment is all set, we are processing..." << endl;

	pair<int, double> result = get_max(max_counter, cost, time_limit, customer_cnt, cus);

	print_result(result.first, result.second);

	string clear_or_not;
	cout << "Would you like us help you delete all the information files (i.e. xxx.txt) ?" << endl;
	cout << "'YES' / 'NO' ? : ";
	cin >> clear_or_not;
	if (clear_or_not == "YES") {
		cout << endl << endl << "Are you sure?" << endl;
		cout <<  "'YES' / 'NO' ? : ";
        cin >> clear_or_not;
        if (clear_or_not == "YES") {
            int return_value = clear();
            cout << endl << endl << "Cleared all the files with a suffix '.txt'! Thank you!" << endl << endl << endl;
        }
	}
}

