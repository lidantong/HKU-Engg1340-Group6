#include <stdio.h>
#include <math.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "customer.h"
#include <iomanip>
using namespace std;

float f(float x, float y, float z) 
{
	float a = x * x + 9.0f / 4.0f * y * y + z * z - 1;
	return a * a * a - x * x *z * z * z - 9.0f / 80.0f * y *y *z * z * z;
}

float h(float x, float z) 
{
	for (float y = 1.0f; y >= 0.0f; y-=0.001f)
		if (f(x, y, z) <= 0.0f)
			return y;
	return 0.0f;
}

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

void add_a_customer (vector<customer> customer_vec) 
{
	// customer new_customer();
	vector<istringstream> info_string_vec;
	cout << "How would you like to initialise a new customer ?" << endl;
	cout << "'manual' / 'file' ? : ";

	// Flag of sources: manual or file
	string command;
	cin >> command;

	// After getting the flag of the source, the following branch produces a well-prepared istringstream vector of goods

	if (command == "manual") {
		// Com is the flag for ending the grocerry input
		string com;
		// Name is good's name, t is time for checking of each item, price, count is how many items do the customer have.
		string name, t, price, count, total;
		// Aquire the information from user.
		input_an_item(name, t, price, count);
		total = name + ' ' + t + ' ' + price + ' ' + count;
		// Initialise the istringstream object with the total which is 4 words
		istringstream info_string (total);
		info_string_vec.push_back(info_string);
		// Continue to get more goods' info or not
		cout << "Wanna continue?" << endl << "'yes' / 'no' ? : ";
		cin >> com;

		while (com != "no") {

			input_an_item(name, t, price, count);
			total = name + ' ' + t + ' ' + price + ' ' + count;

			istringstream info_string (total);
			info_string_vec.push_back(info_string);

			cout << "Wanna continue?" << endl << "'yes' / 'no' ? : ";
			cin >> com;
		}
		cout << "Input is being processed..." << endl;
	}
	else if (command == "file") {

		// Input the filename
		string filename;
		cout << "Please input the filename containing information of one customer: ";
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
			istringstream info_string (info);
			info_string_vec.push_back(info_string);
		}
		cout << "Successfully loaded the file and customer's info is being processed..." << endl;
	}

	if (info_string_vec.empty()) {
		cout << "Error, customer cannot be initialised with the information given, please check again!" << endl;
		return;
	}
	// Initialising a new customer with the info_string_vec
	customer new_customer;
	new_customer.read(info_string_vec);
	// Add the new customer into the existing vector of customers
	customer_vec.push_back(new_customer);
	// Return a success message to user screen
	cout << "Customer successfully initialised! Thank you!" << endl;
}

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

void print_man () 
{
	cout.setf (ios::left);
	cout << "----------------------------------------------------" << endl;
	cout << '|' << setw(15) << "Command" << '|' << setw(35) << "Function" << '|' << endl;
	cout << "----------------------------------------------------" << endl;
	cout << '|' << setw(15) << "ADD" << '|' << setw(35) << "Add a customer into the line." << '|' << endl;
	cout << "----------------------------------------------------" << endl;
	cout << '|' << setw(15) << "Done" << '|' << setw(35) << "Finished input of customers." << '|' << endl;
	cout << "----------------------------------------------------" << endl;
	cout.unsetf(ios::left);
	cout << endl << endl;
}

void print_env (int max_counter, int customer_cnt, double cost, double time_limit) 
{
	cout.setf (ios::left);
	cout << "****************************************************" << endl;
	cout << "****************************************************" << endl;
	cout << "***      " << setw(15) << "Max_counter: " << setw(25) << max_counter << "***" << endl;
	cout << "***      " << setw(15) << "Customer_cnt: " << setw(25) << customer_cnt << "***" << endl;
	cout << "***      " << setw(15) << "Cost: " << setw(25) << cost << "***" << endl;
	cout << "***      " << setw(15) << "Time_limit: " << setw(25) << time_limit << "***" << endl;
	cout.unsetf(ios::left);
	cout << "****************************************************" << endl;
	cout << "****************************************************" << endl;
	cout << endl << endl;
}

void update_env (int &max_counter, int &customer_cnt, double &cost, double &time_limit)
{
	cout << "Type in the value you want to set: " << endl;
	cout << "====================================================" << endl;
	cout << "(int)max_counter" << '[' <<  max_counter << "]: ";
	cin >> max_counter;
	cout << "====================================================" << endl;

	cout << "(int)customer_cnt" << '[' <<  customer_cnt << "]: ";
	cin >> customer_cnt;
	cout << "====================================================" << endl;

	cout << "(double)cost" << '[' <<  cost << "]: ";
	cin >> cost;
	cout << "====================================================" << endl;

	cout << "(double)time_limit" << '[' <<  time_limit << "]: ";
	cin >> time_limit;
	cout << "====================================================" << endl;

}

void print_result (int best_no_of_counter, double revenue) 
{
	cout << endl << endl << endl;
	cout << "PROCESSING... ..." << endl;
	cout << endl << endl << endl;
	cout << "To get the best profit" << endl;
	cout << "The number of counter should be: " << best_no_of_counter << endl;
	cout << "The best revenue youcan get is: " << revenue << endl;
	cout << endl << endl;
	cout << "Thank you for using !" << endl;
}
