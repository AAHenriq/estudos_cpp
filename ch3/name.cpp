// read and write a first name
#include "../ch2/std_lib_facilities.h"

int main()
{
    cout << "Please enter your first name and age\n";
    string first_name; // string variable
    int age = -1;           // integer variable
    cin >> first_name; // read a string
    cin >> age;        // read an integer
    cout << "Hello, " << first_name << " (age " << age << ")" << endl;
}