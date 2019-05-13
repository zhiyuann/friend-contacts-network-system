

#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

int main(){

    long int value = 0;
    string str;
    stringstream ss;

    // reading from input and storing in long int:
    cout << "Enter phone number, with or without dashes: ";
    cin >> str;
    str.erase(remove(str.begin(), str.end(), '-'), str.end());
    ss << str;
    ss >> value;
    cout << "Long int value is: " << value << endl;

   // Writing the number in output with dashes, using the long int
   stringstream ss2;
   string str2;
   ss2 << value;
   ss2 >> str2;
   cout << str2.substr(0, 3) << "-" << str2.substr(3, 3) << "-" << str2.substr(6) <<  endl;


    return 0;
}
