//System Libraries
#include <iostream>   //Input/Output objects

using namespace std;  //Name-space used in the System Library

//User Libraries

//Global Constants

//Function prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declaration of Variables
    int num;
    char input;
    
    //Input values
    cout << "Please input integer" << endl;
    cin >> num;
    cout << "1) test if number is divisible by 3" << endl;
    cout << "2) test if number is between 10 and 100" << endl;
    cout << "Input a 1 or 2" << endl;
    cin >> input;
    
    //Process values
    if (input == '1'){
        if (num % 3 == 0) {
            cout << "Number is divisible by 3"<<endl;
        }
        else {
            cout << "Number is not divisible by 3" << endl;
        }
    }
    else if (input == '2'){
        if (num < 10){
            cout << "Number is less than ten" << endl;
        }
        else if ( num > 10 && num < 100 ){
            cout << "Number is in between 10 and 100" << endl;
        }
        else {
            cout << "Number is greater than 100" << endl;
        }
    }
    else {
        cout << "This did not work" << endl;
    }
    
    //Exit Program
    return 0;
}