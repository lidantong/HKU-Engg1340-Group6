#include <vector>
#include <iostream>
#include <sstream>
using namespace std;

int main () {
  vector<istringstream> svec;
  istringstream x ("asdfadf asdf");
  svec.push_back(x);
  // istringstream &y = x ;
  // string m;
  // y >> m;
  // cout << m << endl;
}