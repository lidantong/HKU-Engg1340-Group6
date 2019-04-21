#include <iostream>
#include <string>
#include <vector>
#include "customer.h"

using namespace std;

void add_a_customer (vector<customer>) {
  // customer new_customer();
  string name;
  double time, price;

	cout << "\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\" << endl << endl;

	cout << "Please type in the information of the grocerry good: " << endl << endl;
	cout << "--------------------------------------------------------------------------------" << endl << endl;

	cout << "=> Good's name: ";
	getline(cin, name);
	cout << endl << endl;

	cout << "--------------------------------------------------------------------------------" << endl << endl;

	cout << "=> The time one item takes when checking out (unit: second): ";
	cin >> time;
	cout << endl << endl;

	cout << "--------------------------------------------------------------------------------" << endl << endl;

	cout << "=> The price of each item (unit: HKD): ";
	cin >> price;
	cout << endl << endl;

	cout << "Perfect, information is processed." << endl << endl;
	cout << "\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\" << endl << endl;

}
void print_logo () {
	cout << "this is our logo" << endl << endl;
}
void print_man () {
	cout << "this is command manual" << endl << endl;
}
void print_env (int max_counter, int customer_cnt, double cost, double time_limit) {
	cout << "max_counter: " << max_counter << endl;
	cout << "customer_cnt: " << customer_cnt << endl;
	cout << "cost: " << cost << endl;
	cout << "time_limit: " << time_limit << endl << endl;
}
void update_env (int &max_counter, int &customer_cnt, double &cost, double &time_limit) {
	cout << "max_counter" << '[' <<  max_counter << ']: ';
  cin >> max_counter;
  cout << endl;

	cout << "customer_cnt" << '[' <<  customer_cnt << ']: ';
  cin >> customer_cnt;
  cout << endl;

	cout << "cost" << '[' <<  cost << ']: ';
  cin >> cost;
  cout << endl;

	cout << "time_limit" << '[' <<  time_limit << ']: ';
  cin >> time_limit;
  cout << endl;

}
void print_result (int best_no_of_counter, double revenue) {
  cout << best_no_of_counter << ' ' << revenue << endl;
}
