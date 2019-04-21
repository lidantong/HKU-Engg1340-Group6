#include <iostream>
#include <string>
#include "grocery.h"


// -------------------------------------------------------------------------------- Standard line1
// \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\ Standard line2

bool toLower(string x) {
	for (auto &c: x) {
		if (ispunct(c)) return false;
		tolower(c);
	}
	return true;
}

void g::readFromFile(string filename) {
	cin >> name >> count >> time >> price;
}


void g::readFromUser () {

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


	// cout << "Please input the file name containing information of groceries (e.g.grocerry.txt)" << endl;
	// cout << "Your input: " << endl;
	// string filename;
	// if (cin >> filename) {
	//  cout << "Woo, perfect! Is there any extra piece of information you want to add?" << endl;
	//   cout << "Type 'yes' is you want to add; 'no' if that's all: " << endl;
	// }
	// string command_on_input_mannually;
	// cin >> command_on_input_mannually;
	// if (command_on_input_mannually == "yes") {

	// }
	// else if (command_on_input_mannually == "no")
	//   cout << "Alright, we are all set!" << endl;
	// else
	//   cout << "Sorry, please type in either 'yes' or 'no'." << endl << "Type 'yes' is you want to add; 'no' if that's all: " << endl;



	cin >> name >> count >> time >> price;
}