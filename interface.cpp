#include <stdio.h>
#include <math.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "customer.h"
#include <iomanip>
#include <cstdlib>
using namespace std;


// Preparation for logo
float f(float x, float y, float z)
{
	float a = x * x + 9.0f / 4.0f * y * y + z * z - 1;
	return a * a * a - x * x *z * z * z - 9.0f / 80.0f * y *y *z * z * z;
}

// Preparation for logo
float h(float x, float z)
{
	for (float y = 1.0f; y >= 0.0f; y-=0.001f)
		if (f(x, y, z) <= 0.0f)
			return y;
	return 0.0f;
}

// User interaface, manual input
// takes strings of name, time, price, count
// input the four variables by the user input
void input_an_item (string &name, string &t, string &price, string &count)
{
	cout << "\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\" << endl << endl;

	cout << "Please type in the information of the grocerry good: " << endl << endl;
	cout << "--------------------------------------------------------------------------------" << endl << endl;

	cout << "=> Good's name (one_word): ";
	cin >> name;
	cout << endl << endl;

	cout << "--------------------------------------------------------------------------------" << endl << endl;

	cout << "=> The time one item takes when checking out (unit: second): ";
	cin >> t;
	cout << endl << endl;

	cout << "--------------------------------------------------------------------------------" << endl << endl;

	cout << "=> The price of each item (unit: HKD): ";
	cin >> price;
	cout << endl << endl;

	cout << "=> The number of this kind of item: ";
	cin >> count;
	cout << endl << endl;

	cout << "Perfect, information is processed." << endl << endl;
	cout << "\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\" << endl << endl;

}

// Core function for adding a customer manually or by file
// takes a customer vector
// add one new customer to that vector
// the returned bool value decide whether the customer is successfully initlaised
// If so, the custoemr_cnt can add by one
// If not so, the number will not change
bool add_a_customer (vector<customer> &customer_vec)
{
	// Create a string to store all the information
	string info_string_total;

	cout << endl << "How would you like to initialise a new customer ?" << endl << endl;
	cout << "'MANUAL' / 'FILE' ? : ";

	// Flag of sources: manual or file
	string command;
	cin >> command;

	// After getting the flag of the source, the following branch produces a well-prepared istringstream vector of goods

	if (command == "MANUAL") {

		// Com is the flag for ending the grocerry input
		string com;

		// Name is good's name, t is time for checking of each item, price, count is how many items do the customer have.
		string name, t, price, count, total;

		// Aquire the information from user.
		input_an_item(name, t, price, count);
		total = name + ' ' + t + ' ' + price + ' ' + count + ' ';

		// Add to the total string
		info_string_total += total;

		// Continue to get more goods' info or not
		cout << "Wanna continue?" << endl << "'YES' / 'NO' ? : ";
		cin >> com;

		// keep input new kind of items to be purchased by this user
		while (com != "NO") {
			
			// Get the four core information
			input_an_item(name, t, price, count);
			total = name + ' ' + t + ' ' + price + ' ' + count + ' ';
			info_string_total += total;
	
			cout << "Wanna continue?" << endl << "'YES' / 'NO' ? : ";
			cin >> com;
		}

		// One customer is initilaised
		cout << endl << "Input is being processed..." << endl << endl;
	}

	else if (command == "FILE") {

		// Input the filename
		string filename;
		cout << endl << "Please input the filename containing information of one customer: ";
		cin >> filename;

		// Try to open the file
		ifstream fin;
		fin.open(filename.c_str());

		// If the file can not be opened
		while (fin.fail()) {
			cout << "Sorry, NameError!" << endl << "Please input filename again: ";
			cin >> filename;
			fin.open(filename.c_str());
		}

		// Fin is successfully loaded:
		string info;
		while (getline(fin, info)) {
			info_string_total += (info + ' ');
		}

		cout << endl << endl << "Successfully loaded the file and customer's info is being processed..." << endl << endl << endl;
		fin.close();
	}

	// If the information read into the customer is empty that is to indicate an error in the process
	// false can stop the customer_cnt from incrementing
	if (info_string_total.empty()) {
		cout << endl << "Error, customer cannot be initialised with the information given, please check again!" << endl << endl;
		return false;
	}

	// Initialising a new customer with the info_string_vec
	customer new_customer;
	new_customer.read(info_string_total);

	// Add the new customer into the existing vector of customers
	customer_vec.push_back(new_customer);

	// Return a success message to user screen
	cout << "Customer successfully initialised! Thank you!" << endl << endl << endl;
	return true;
}

// Print the logo of our programme which is a delicated heart
void print_logo ()
{
	for (float z = 1.5f; z > -1.5f; z -= 0.05f)
	{
		for (float x = -1.5f; x < 1.5f; x += 0.025f) {
			float v = f(x, 0.0f, z);
			if (v <= 0.0f) {
				float y0 = h(x, z);
				float ny = 0.01f;
				float nx = h(x + ny, z) - y0;
				float nz = h(x, z + ny) - y0;
				float nd = 1.0f / sqrtf(nx * nx + ny * ny + nz * nz);
				float d = (nx + ny - nz) * nd * 0.5f + 0.5f;
				putchar(".:-=+*#%@"[(int)(d * 5.0f)]);
			}
			else
				putchar(' ');
		}
		putchar('\n');
	}

}

// Print the manual page for the user
void print_man ()
{
	cout.setf (ios::left);
	cout << "----------------------------------------------------" << endl;
	cout << '|' << setw(15) << "Command" << '|' << setw(35) << "Function" << '|' << endl;
	cout << "----------------------------------------------------" << endl;
	cout << '|' << setw(15) << "ADD" << '|' << setw(35) << "Add a customer into the line." << '|' << endl;
	cout << "----------------------------------------------------" << endl;
	cout << '|' << setw(15) << "TEST" << '|' << setw(35) << "Generate random customers to test." << '|' << endl;
	cout << "----------------------------------------------------" << endl;
	cout << '|' << setw(15) << "EXIT" << '|' << setw(35) << "Exit the programme." << '|' << endl;
	cout << "----------------------------------------------------" << endl;
	cout << '|' << setw(15) << "DONE" << '|' << setw(35) << "Finished input of customers." << '|' << endl;
	cout << "----------------------------------------------------" << endl;
	cout.unsetf(ios::left);
	cout << endl << endl;
}

// Print the environment variables fot the user to check
void print_env (int max_counter, int customer_cnt, double cost, double time_limit)
{
	cout.setf (ios::left);
	cout << "****************************************************" << endl;
	cout << "****************************************************" << endl;
	cout << "***      " << setw(20) << "Max_counter: " << setw(20) << max_counter << "***" << endl;
	cout << "***      " << setw(20) << "Customer_cnt: " << setw(20) << customer_cnt << "***" << endl;
	cout << "***      " << setw(20) << "Cost_per_cashier: " << setw(20) << cost << "***" << endl;
	cout << "***      " << setw(20) << "Time_limit: " << setw(20) << time_limit << "***" << endl;
	cout.unsetf(ios::left);
	cout << "****************************************************" << endl;
	cout << "****************************************************" << endl;
	cout << endl << endl;
}

// Change the environment
// Takes a maximum counter number, a customer counter number, 
// 		the cost of opening a new cashier and the time limit that people are gonna wait
// use references to update their values
void update_env (int &max_counter, int &customer_cnt, double &cost, double &time_limit)
{
	cout << "Type in the value you want to set: " << endl;
	cout << "====================================================" << endl;
	cout << "(int)max_counter" << '[' <<  max_counter << "]: ";
	cin >> max_counter;
	cout << "====================================================" << endl;

	// cout << "(int)customer_cnt" << '[' <<  customer_cnt << "]: ";
	// cin >> customer_cnt;
	// cout << "====================================================" << endl;

	cout << "(double)cost" << '[' <<  cost << "]: ";
	cin >> cost;
	cout << "====================================================" << endl;

	cout << "(double)time_limit" << '[' <<  time_limit << "]: ";
	cin >> time_limit;
	cout << "====================================================" << endl;

}

// Print the result for the user
// take the best number of counters and the corresponding revanue
void print_result (int best_no_of_counter, double revenue)
{
	cout << endl << endl << endl;
	cout << "PROCESSING... ..." << endl;
	cout << endl << endl << endl;
	cout << "To get the best profit" << endl << endl;
	cout << "The number of counter should be: " << best_no_of_counter << endl << endl;
	cout << "The best revenue you can get is: " << revenue << endl;
	cout << endl << endl;
	cout << "Thank you for using !" << endl << endl << endl;
}

// autofill is for test only
// take a vector of customers and a vector of filenames
// 		where each file contains a customer's information
// generate random customers into the vector
void autofill (vector<customer> &customer_vec, vector<string> names)
{

	// process the names vector to give out a total string
	for (string filename: names) {
		
		// create a total string to store all the information
		string info_string_total = "";

		// open a file
		ifstream fin;
		fin.open(filename.c_str());

		// Fin is successfully loaded:
		string info;
		while (getline(fin, info)) {
			info_string_total += (info + ' ');
		}

		// create and initialise a new customer
		customer new_customer;
		new_customer.read(info_string_total);

		// Add the new customer into the existing vector of customers
		customer_vec.push_back(new_customer);

		// Return a success message to user screen
		cout << "Customer successfully initialised! Thank you!" << endl;
		fin.close();
	}
}

// clear the .txt files and return the status code, 0 is success
int clear() {
	return system("rm -rf *.txt");
}