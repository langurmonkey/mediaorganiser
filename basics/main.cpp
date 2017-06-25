#include <iostream>
#include <string>
#include "add.hpp"

using namespace std;

int main()
{
    cout << "The sum of 3 and 4 is: " << add(3, 4) << endl;
    int32_t a{};
    long b{};
    long int c{};
    cout << sizeof(a) << " " << sizeof(b) << " " << sizeof(c) << endl;

    float d{};
    double e{};
    long double f{};
    cout << sizeof(d) << " " << sizeof(e) << " " << sizeof(f) << endl;

    if(a){
        cout << "A is true";
    }
    a = 100;
    if(a){
        cout << "A is true after init to non-zero" << endl;
    }

    char ch(36);
    cout << ch << endl;
    ch += 4;
    cout << ch << endl;


    string s("HI there");
    cout << s << endl;

    int bin = 0b0100'1001'0001;
    cout << bin << endl;
    return 0;
}

