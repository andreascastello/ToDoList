#include <iostream>
#include <stdio.h>
#include <string>
#include <array>

using namespace std;
auto main() -> int
{
    string chandler;
    string str;
 
    cout << "Please enter your name: \n";
    getline(cin, chandler);

    cout << "Hello, " << chandler << endl;

    return 0;
}
