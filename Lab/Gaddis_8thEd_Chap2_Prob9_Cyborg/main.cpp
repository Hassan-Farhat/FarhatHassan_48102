/* 
 * File:   main.cpp
 * Author: Hassan Farhat
 * Created on September 8, 2016, 12:03 PM
 * Purpose : Display the Byte count and ranges of data types
 */
//System Libraries
#include <iostream>   //Input/Output objects
using namespace std;  //Name-space used in the System Library

//User Libraries

//Global Constants

//Function prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Display Output
    cout<<"The size of a boolean             = "<< sizeof(bool) << "byte";
    cout << "  [0 - > false, true otherwise]"<< endl;
    cout<<"The size of a character           = "<< sizeof(char) << "byte";
    cout << "  [-2^7,2^7-1],[-128,127]"<< endl;
    cout<<"The size of an unsigned character = "<< sizeof(unsigned char) << "byte";
    cout << "  [0,2^8-1],[,255]"<< endl;
    cout<<"The size of a short               = "<< sizeof(short) << "bytes";
    cout << " [-2^15,2^15-1],[-32768,32767]"<< endl;
    cout<<"The size of an unsigned short     = "<< sizeof(unsigned short) << "bytes";
    cout << " [0,2^16-1],[0,65535]"<< endl;
    cout<<"The size of an integer            = "<< sizeof(int) << "bytes";
    cout << " [-2^31,2^31-1],[+- 2.15 Billion]"<< endl;
    cout<<"The size of a unsigned integer    = "<< sizeof(unsigned int) << "bytes";
    cout << " [0,2^32-1],[+ 4.3 Billion]"<< endl;
    cout<<"The size of a long                = "<< sizeof(long) << "bytes";
    cout << " [-2^63,2^63-1],[+- 9.2^18 (quintillion)]"<< endl;
    cout<<"The size of a unsigned long       = "<< sizeof(unsigned long) << "bytes";
    cout << " [0,2^64-1],[+- 18.4^18 (quintillion)]"<< endl;
    cout<<"The size of a float               = "<< sizeof(float) << "bytes";
    cout << " [10^+-38], 7 SD"<< endl;
    cout<<"The size of a double              = "<< sizeof(double) << "bytes";
    cout << " [10^+-308], 16 SD"<< endl;
    cout<<"The size of a long double         = "<< sizeof(long double) << "bytes";
    cout << "[10^+-4932] , 34 SD"<< endl;
    
    
    //Exit Program
    return 0;
}