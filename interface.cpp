#include <stdio.h>
#include <math.h>
#include <iostream>
#include <string>
#include <vector>
#include "customer.h"
#include <iomanip>
using namespace std;

float f(float x, float y, float z) {
	float a = x * x + 9.0f / 4.0f * y * y + z * z - 1;
	return a * a * a - x * x *z * z * z - 9.0f / 80.0f * y *y *z * z * z;
}
float h(float x, float z) {
	for (float y = 1.0f; y >= 0.0f; y-=0.001f)
		if (f(x, y, z) <= 0.0f)
			return y;
	return 0.0f;
}

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

void print_man () {
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

void print_env (int max_counter, int customer_cnt, double cost, double time_limit) {
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

void update_env (int &max_counter, int &customer_cnt, double &cost, double &time_limit) {
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

void print_result (int best_no_of_counter, double revenue) {
	cout << endl << endl << endl;
	cout << "PROCESSING... ..." << endl;
	cout << endl << endl << endl;
	cout << "To get the best profit" << endl;
	cout << "The number of counter should be: " << best_no_of_counter << endl;
	cout << "The best revenue youcan get is: " << revenue << endl;
	cout << endl << endl;
	cout << "Thank you for using !" << endl;
}
