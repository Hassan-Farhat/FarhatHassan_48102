/* 
 * File:   main.cpp
 * Author: Hassan
 *
 * Created on October 15, 2016, 4:05 PM
 */

#include <iostream>

using namespace std;


int main(int argc, char** argv) {
    for (int i = 1; i <= 10; i++) {
        int op = i%4;
        cout << op << endl;
    }
    return 0;
}

