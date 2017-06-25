#include <iostream>
#include <chrono>
#include <thread>
#include <string>
#include "add.hpp"

using namespace std;

#define N 10

int main()
{
    for(int i = 0; i < N; i++){
        int a = pow(2, i);
        cout << '\r'
             << "pow(2, " << i << ") = "
             << a
             << flush;
        this_thread::sleep_for(chrono::milliseconds(200));
    }

    cout << endl;

    int a = 1;
    for(int i =0; i < N; i++){
        cout << "a = " << a << endl;
        a = a << 1;
    }
    return 0;
}

