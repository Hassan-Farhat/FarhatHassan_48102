/*
 * File:   main.cpp
 * Author: Hassan Farhat
 * Created on November 13, 2016, 5:06 PM
 * Purpose : Menu with all the Assignment 6 answers.
 */

//System Libraries
#include <iostream>   //Input/Output objects
#include <iomanip>    //For output manipulation
#include <string>
#include <cstdlib>    //Random number  
#include <ctime>      //Time
#include <vector>
using namespace std;  //Name-space used in the System Library

//User Libraries

//Global Constants
const int NUMDAYS = 5;
const int COLS = 3;
const int GRADES = 4;

//Function prototypes

void SrchAcc(int [], int, bool &);
void SortAcc(int []);
void Select(string[], int);
void PntName(string[]);
int nameSch(string[], int, string);
void FilList (int[], int);
void SrtList (int[], int);
void LinTest (int[], int, int);
void BinTest (int[], int, int);
void PrtList (int[], int, int);
void FillAry(int[], int[], int[], int);
void Bubble(int[], int, int &);
void Select(int[], int, int &);
void MrkSort(int[], int, int &);
void PntArys(int[], int[], int[], int, int, int, int);
void PntArys(int[], int);
void fill(int [], int);
void fill(int [], int);
void filvctr(vector<int> &);
void sort(int [], int);
int srch(int [], int, int, int &);
void prnt(int [], int);
void disTbl(vector<int>, vector<int>);
void Letters(char[]);
int search(string, char);
void pntTbl(string, char[], int[]);
void problem1();
void problem2();
void problem3();
void problem4();
void problem5();
void problem6();
void problem7();
void problem8();
void problem9();
void problem10();

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declaration of Variables
    int menuItm;    //Choice from menu
    
    //Loop until users exits
    do{
    
        //Prompt for problem for user input
        cout<<"1.  Type 1  for Gaddis 8thEd Ch8 Prob1 AccValid"<<endl;
        cout<<"2.  Type 2  for Gaddis 8thEd Ch8 Prob2 LotteryWinners"<<endl;
        cout<<"3.  Type 3  for Gaddis 8thEd Ch8 Prob3 LotteryWinners(binary)"<<endl;
        cout<<"4.  Type 4  for Gaddis 8thEd Ch8 Prob4 AccValid(binary)"<<endl;
        cout<<"5.  Type 5  for Gaddis 8thEd Ch8 Prob6 StringSlctSort"<<endl;
        cout<<"6.  Type 6  for Gaddis 8thEd Ch8 Prob7 StringBinary"<<endl;
        cout<<"7.  Type 7  for Gaddis 8thEd Ch8 Prob8 SearchBenchmarks"<<endl;
        cout<<"8.  Type 8  for Gaddis 8thEd Ch8 Prob9 SortingBenchmarks"<<endl;
        cout<<"9.  Type 9  for Savitch 9thEd Ch7 Prob5 numRepeats"<<endl;
        cout<<"10. Type 10 for Savitch 9thEd Ch7 Prob8 LetterCount"<<endl;
        cin>>menuItm;

        //Go to the Problem
        switch(menuItm){
            case 1:problem1();break;
            case 2:problem2();break;
            case 3:problem3();break;
            case 4:problem4();break;
            case 5:problem5();break;
            case 6:problem6();break;
            case 7:problem7();break;
            case 8:problem8();break;
            case 9:problem9();break;
            case 10:problem10();
        }//End the Switch/Case
    }while(menuItm>0&&menuItm<=10);//Ends the Do-While Loop

    //Exit Program
    return 0;
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//****************** Gaddis 8thEd Ch8 Prob1 AccValid ***************************
//Purpose:  Find the users account
//Inputs:   Inputs to the function here  -> Description, Range, Units
//Output:   Outputs to the function here -> Description, Range, Units
//******************************************************************************
void problem1(){
    //Declaration of Variables
    const int SIZE = 100;
    int acc[SIZE] = {0 ,5658845, 4520125, 7895122, 8777541, 8451277, 1302850,      //The account numbers
                     8080152, 4562555, 5552012, 5050552, 7825877, 1250255,
                     1005231, 6545231, 3852085, 7576651, 7881200, 4581002};
    int input;          //The user input 
    bool found = false;  //Used to break out of the loop
    
    //Input values
    cout << "Please type in the account number:"<< endl;
    cin >> input;
    
    //Linear search
    for (int i = 1; i<18 && found == false; i++){
        if(input == acc[i]) found = true;
    }
    
    //Display Output
    if (found == true) cout << endl << "We found your account" << endl;
    else { //If item could not be found.
        cout << endl << "We could not find your account sorry." << endl;
        cout << "Our current accounts are:" << endl;
        for (int i = 1; i < 18; i++){
            cout << acc[i] << "   ";
            if (i%4 == 0) cout << endl;
        }
        cout << endl;
    }
    //Exit Program
}

//*****************************END OF PROBLEM***********************************

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//******************* Gaddis 8thEd Ch8 Prob2 LotteryWinners ********************
//Purpose:  Lottery simulator
//Inputs:   Inputs to the function here  -> Description, Range, Units
//Output:   Outputs to the function here -> Description, Range, Units
//******************************************************************************

void problem2(){
    //Declaration of Variables
     const int SIZE = 100;
    int lot[SIZE] = {0, 13579, 26791, 26792, 33445, 55555,  //The lottery numbers
                     62483, 77777, 79422, 85647, 93121};
    int input;           //The user input 
    bool found = false;  //Used to break out of the loop
    
    //Input values
    cout << "Input your lottery 5 digit number:"<< endl;
    cin >> input;
    
    //Linear search
    for (int i = 1; i<11 && found == false; i++){
        if(input == lot[i]){
            found = true;
            cout << endl << "Your numbers were correct" << endl;
            cout << "Your numbers: " << input << endl;
            cout << "The lottery numbers: " << lot[i] << endl;
        }
    }
    if (found == false){
        cout << "Your numbers where incorrect" << endl;
        cout << "This weeks numbers are:" << endl;
        for (int k = 1; k < 11; k++){
            cout << lot[k] << "   ";
            if (k%4 == 0) cout << endl;
        }
        cout << endl;
    }
    //Exit Program
}

//*****************************END OF PROBLEM***********************************

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//**************** Gaddis 8thEd Ch8 Prob3 LotteryWinners(binary) ***************
//Purpose:  Lottery simulator.
//Inputs:   Inputs to the function here  -> Description, Range, Units
//Output:   Outputs to the function here -> Description, Range, Units
//******************************************************************************
void problem3(){
    //Declaration of Variables
    const int SIZE = 100;
    int lot[SIZE] = {0, 13579, 26791, 26792, 33445, 55555,  //The lottery numbers
                     62483, 77777, 79422, 85647, 93121};
    int input,                 //The user input 
        first = 0,             // First array element       
        last = 11 - 1,         // Last array element       
        middle,                // Mid point of search       
        pos = -1;              // Position of search value
    bool found = false;        //Used to break out of the loop
    
    //Input values
    cout << "Input your lottery 5 digit number:"<< endl;
    cin >> input;
    
    //Binary search
    do{ 
        middle = (first+last)/2;    //Calculate the middle point
        if (lot[middle]==input){
            found = true;
            pos = middle;
            cout << "Your lottery numbers were correct !" << endl;
            cout << "Your numbers = " << input << endl;
            cout << "The lottery numbers = " << lot[middle] << endl;
        }
        else if (lot[middle] > input) last = middle-1;
        else first = middle+1;
    }while (found == false && first <= last);
    
    if (found == false){//Display if the numbers could not be found
            cout << "Your numbers where incorrect" << endl;
            cout << "This weeks numbers are:" << endl;
            for (int k = 1; k < 11; k++){
                cout << lot[k] << "   ";
                if (k%4 == 0) cout << endl;
            }
            cout << endl;
        }
    
    //Exit Program
}

//*****************************END OF PROBLEM***********************************

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//******************* Gaddis 8thEd Ch8 Prob4 AccValid(binary) ******************
//Purpose:  Account validation using a binary search
//Inputs:   Inputs to the function here  -> Description, Range, Units
//Output:   Outputs to the function here -> Description, Range, Units
//******************************************************************************
void problem4(){
    //Declaration of Variables
    const int SIZE = 100;
    int acc[SIZE] = {0 ,5658845, 4520125, 7895122, 8777541, 8451277, 1302850,      //The account numbers
                     8080152, 4562555, 5552012, 5050552, 7825877, 1250255,
                     1005231, 6545231, 3852085, 7576651, 7881200, 4581002};
    int input;          //The user input 
    bool found = false;  //Used to break out of the loop
    
    //Input values
    cout << "Please type in the account number:"<< endl;
    cin >> input;
    
    //Sort:
    SortAcc(acc);
    
    //Binary search:
    SrchAcc(acc, input, found);
    
    //Display Output
    if (found == true) cout << endl << "We found your account" << endl;
    else { //If item could not be found.
        cout << endl << "We could not find your account sorry." << endl;
        cout << "Our current accounts are:" << endl;
        for (int i = 1; i < 18; i++){
            cout << acc[i] << "   ";
            if (i%4 == 0) cout << endl;
        }
        cout << endl;
    }
    //Exit Program
}

//Sort the accounts:
void SortAcc(int acc[]){
    int minI, minV;     //Minimum Index, Minimum Value
    for(int s = 0; s < 18 - 1; s++){
        minI = s;
        minV = acc[s];
        for(int i = s+1; i<18; i++){
            if (acc[i] < minV){
                minV = acc[i];
                minI = i;
            }
        }
        acc[minI] = acc[s];
        acc[s] = minV;
    }
}

//Search the for the account:
void SrchAcc(int acc[], int input, bool &found){
    int first = 0,             // First array element       
        last = 18 - 1,         // Last array element       
        middle,                // Mid point of search       
        pos = -1;              // Position of search value
    do{ 
        middle = (first+last)/2;    //Calculate the middle point
        if (acc[middle]==input){
            found = true;
            pos = middle;
        }
        else if (acc[middle] > input) last = middle-1;
        else first = middle+1;
    }while (found == false && first <= last);
}

//*****************************END OF PROBLEM***********************************

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//******************* Gaddis 8thEd Ch8 Prob6 StringSlctSort ***********************
//Purpose:  Use a select sort on a string array
//Inputs:   Inputs to the function here  -> Description, Range, Units
//Output:   Outputs to the function here -> Description, Range, Units
//******************************************************************************
void problem5(){
    //Declaration of Variables
    const int SIZE = 12;
    string names[SIZE]={"Hassan","Peter","Jesse","James","Mohammed","Osama",
                        "David","Phillip","Philip","Felix","Ali", "Sam"};
    int n=12;
    
    //Display unsorted array
    PntName(names);
    
    //Sort he array
    Select(names,n);
    
    //Display Sorted Array:
    cout << endl;
    PntName(names);
    cout << endl;
    //Exit Program
}

//*****************************END OF PROBLEM***********************************

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//******************* Gaddis 8thEd Ch8 Prob7 StringBinary **********************
//Purpose:  Search an array of strings
//Inputs:   Inputs to the function here  -> Description, Range, Units
//Output:   Outputs to the function here -> Description, Range, Units
//******************************************************************************
void problem6(){
   //Declaration of Variables
    const int SIZE = 12;
    string names[SIZE]={"Hassan","Peter","Jesse","James","Mohammed","Osama",
                        "David","Phillip","Philip","Felix","Ali", "Sam"},
            name;           //Name to search for
    int n=12, loc;
    
    //Sort he array
    Select(names,n);
    
    //Enter the name to search for:
    cout<<"What name are you looking for?"<<endl;
    cin >> name;
    
    //Search for the name
    loc = nameSch(names, n, name);
    
    //Display Output:
    if (loc == -1){ 
        cout << "We were unable to find the name in the list." << endl;
        cout << "This is the list of names:" << endl;
        PntName(names);
    }
    else cout<<"We found the name: " << names[loc] << endl;
    
    //Exit Program
}

//Select sort:
void Select(string b[], int n){
    string minV;     //Minimum Index, Minimum Value
    int minI;
    for(int s = 0; s < n-1; s++){
        minI = s;
        minV = b[s];
        for(int i = s+1; i<n; i++){
            if (b[i]<minV){
                minV = b[i];
                minI = i;
            }
        }
        b[minI] = b[s];
        b[s] = minV;
    }
}

//Print the array
void PntName(string names[]){
    for (int i=0; i<12; i++){
        cout << names[i] << "  ";
        if ((i+1)%4==0) cout << endl;
    }
}

//Search for the name:
int nameSch(string a[], int n, string t){
    int first = 0,             // First array element       
        last = 11 - 1,         // Last array element       
        middle,                // Mid point of search       
        pos = -1;              // Position of search value
    do{ 
        middle = (first+last)/2;    //Calculate the middle point
        if (a[middle]==t){
            pos = middle;
            return pos;
        }
        else if (a[middle] > t) last = middle-1;
        else first = middle+1;
    }while (first <= last);
    return -1;
}

//*****************************END OF PROBLEM***********************************

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//******************* Gaddis 8thEd Ch8 Prob8 SearchBenchmarks *************************
//Purpose:  Test which searching algorithm is uses less tries
//Inputs:   Inputs to the function here  -> Description, Range, Units
//Output:   Outputs to the function here -> Description, Range, Units
//******************************************************************************
void problem7(){
    //Set random number seed
    srand(static_cast<unsigned int> (time(0)));
    
    //Declaration of Variables
    const int SIZE = 100;
    int numList[SIZE];      //The list of random numbers
    int utilize = 20,       //The utilized portion of the array
        tValue;             //Test value
    
    //Input values
    FilList (numList, utilize);
    tValue = numList[rand()%19 + 1];
    
    //Sort
    SrtList (numList, utilize);
    
    //Linear test
    LinTest (numList, utilize, tValue);
    
    //Binary test
    BinTest (numList, utilize, tValue);
    
    //Print the array and the test value
    PrtList (numList, utilize, tValue);

    //Exit Program
}

//Fill the array with random numbers
void FilList(int a[], int n){
    //Fill the array with 4 digit random numbers
    for (int i=0; i<n; i++){
        a[i] = rand()%999+1;
    }
}

//Sort the array
void SrtList(int a[],int size){
    for(int i=0;i<size-1;i++){
        for(int k=i+1;k<size;k++){
            if(a[i]>a[k]){
                a[i]=a[i]^a[k];
                a[k]=a[i]^a[k];
                a[i]=a[i]^a[k];
            }
        }
    }
}

//Linear test
void LinTest(int a[], int n, int t){
    bool found = false;
    int counter = 0;
    for (int i=0; i<n, !found; i++){
        if (t == a[i]) found = true;
        counter = i+1;
    }
    cout << "The linear search took " << counter << " attempts." << endl;
}

//Binary Search
void BinTest(int a[], int n, int t){
    int counter = 0,           // Counter for the number of attempts
        first = 0,             // First array element       
        last = 11 - 1,         // Last array element       
        middle,                // Mid point of search       
        pos = -1;              // Position of search value
    bool found = false;
    do{ 
        middle = (first+last)/2;    //Calculate the middle point
        if (a[middle]==t){
            found = true;
            pos = middle;
        }
        else if (a[middle] > t) last = middle-1;
        else first = middle+1;
        counter += 1;
    }while (found == false && first <= last);
    cout << "The binary search took " << counter << " attempts." << endl;
}

//Print the number list and its test value:
void PrtList(int a[], int n, int t){
    for (int i=0; i<n; i++){
        cout << setw(4) << a[i];
        if ((i+1)%4 == 0) cout << endl;
    }
    cout << endl << "The number being searched for is " << t << endl;
}

//*****************************END OF PROBLEM***********************************

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//***************** Gaddis 8thEd Ch8 Prob9 SortingBenchmarks *******************
//Purpose:  Benchmark test for the different search types
//Inputs:   Inputs to the function here  -> Description, Range, Units
//Output:   Outputs to the function here -> Description, Range, Units
//******************************************************************************
void problem8(){
    //Set random number seed:
    srand(static_cast<unsigned int> (time(0)));
    
    //Declaration of Variables
    const int SIZE = 100;       //Size of the array.
    int bTest[SIZE],            //Bubble sort test array.
        sTest[SIZE],            //Select sort test array.
        mTest[SIZE];            //Mark sort test array.
    int utilize = 20,           //Utilized portion of array.
        c1,
        c2,
        c3;
    
    //Input values
    FillAry(bTest, sTest, mTest, utilize);
    
    //Print unsorted array:
    PntArys(bTest, utilize);
    
    //Bubble sort test
    Bubble(bTest, utilize, c1);
    
    //Select sort test
    Select(sTest, utilize, c2);
    
    //Mark sort test
    MrkSort(mTest, utilize, c3);
    
    //Display the sorted arrays
    PntArys(bTest, sTest, mTest, utilize, c1, c2, c3);
    
    //Exit Program
}

//Fill the three arrays with 20 random 2 digit numbers:
void FillAry(int a[], int b[], int c[], int n){
    for (int i=0; i<n; i++){
        a[i] = rand()%99+1;
        b[i] = a[i];
        c[i] = b[i];
    } 
}

//Bubble sort:
void Bubble(int a[], int n, int & counter){
    bool swap;
    int temp;
    counter=0;
    do{
        swap = false;
        for(int i=0; i<(n-1); i++){
            if (a[i]>a[i+1]){
                temp = a[i];
                a[i] = a[i+1];
                a[i+1] = temp;
                swap = true;
                counter += 1;
            }
        }
    }while(swap);
    cout << "Bubble sort made " << counter << " switches" << endl;
}

//Select sort:
void Select(int b[], int n, int & counter){
    int minI, minV;     //Minimum Index, Minimum Value
    counter = 0;
    for(int s = 0; s < n-1; s++){
        minI = s;
        minV = b[s];
        for(int i = s+1; i<n; i++){
            if (b[i]<minV){
                minV = b[i];
                minI = i;
                counter += 1;
            }
        }
        b[minI] = b[s];
        b[s] = minV;
    }
    cout << "Select sort made " << counter << " switches" << endl;
}

//Mark sort:
void MrkSort(int c[], int n, int & counter){
    counter = 0;
    for(int i=0;i<n-1;i++){
        for(int k=i+1;k<n;k++){
            if(c[i]>c[k]){
                c[i]=c[i]^c[k];
                c[k]=c[i]^c[k];
                c[i]=c[i]^c[k];
                counter += 1;
            }
        }
    }
    cout << "Mark sort made " << counter << " switches" << endl;
}

//Print the unsorted arrays:
void PntArys(int a[], int n){
    cout << "The array the sorting algorithms must sort :" << endl;
    for (int i = 0; i < n; i++){
        cout << setw(3) << a[i];
        if ((i+1)%4 == 0) cout << endl;
    }
    cout << endl;
}

//Print the arrays:
void PntArys(int a[], int b[], int c[], int n, int c1, int c2, int c3){
    cout << endl << "Bubble sort :" << c1 << " switches" << endl;
    for (int i = 0; i < n; i++){
        cout << setw(3) << a[i];
        if ((i+1)%4 == 0) cout << endl;
    }
    cout << endl;
    
    cout << "Select sort :" << c2 << " switches" << endl;
    for (int i = 0; i < n; i++){
        cout << setw(3) << b[i];
        if ((i+1)%4 == 0) cout << endl;
    }
    cout << endl;
    
    cout << "Bubble sort :" << c3 << " switches" << endl;
    for (int i = 0; i < n; i++){
        cout << setw(3) << c[i];
        if ((i+1)%4 == 0) cout << endl;
    }
    cout << endl;
}


//*****************************END OF PROBLEM***********************************

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//******************* Savitch 9thEd Ch7 Prob5 numRepeats *************************
//Purpose:  Determine the number of times a number appears in an array
//Inputs:   Inputs to the function here  -> Description, Range, Units
//Output:   Outputs to the function here -> Description, Range, Units
//******************************************************************************
void problem9(){
    //Set random number seed:
    srand(static_cast<unsigned int> (time(0)));
    
    //Declaration of Variables
    const int SIZE=100;
    int n=50,           //Amount of spaces used.
        numList[SIZE],  //The Number list to search.
        i=0,            //counter and used to break out of the loop
        c=0,            //The counter
        val;            //The Value to search for.
    vector<int> dups(SIZE),     //The duplicates 
                list(SIZE);     //The number of times the duplicates appear   
        
    
    //Input values
    fill(numList, n);

    
    //Sort the array
    sort(numList, n);
    
    //Display Sorted Array
    prnt(numList, n);
    
    //Fill in the two vectors
    do{
        val = numList[i];
        dups[c] = val;
        list[c] = srch(numList,n,val,i); 
        c+=1;
    }while (i<50);
    
    //Display Table 
    disTbl(dups, list);
    
    //Exit Program
}

//Fill the list with random numbers:
void fill(int numList[], int n){
    for (int i=0; i<n; i++){
        numList[i] = rand()%90+10;
    }
}

//Sort the list:
void sort(int a[], int size){
        for(int i=0;i<size-1;i++){
        for(int j=i+1;j<size;j++){
            if(a[i]>a[j]){
                a[i]=a[i]^a[j];
                a[j]=a[i]^a[j];
                a[i]=a[i]^a[j];
            }
        }
    }
}

//Print the array:
void prnt(int a[],int n){
    cout<<"The Array"<<endl;
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
        if(i%10==9)cout<<endl;
    }
    cout<<endl;
}

//Search for duplicates
int srch(int a[], int n, int v, int &i){
    int j = 0;
    for (int k=i; k<50; k++){
        if(v == a[k]) j+=1;
        else{
            return j;
        }
        i++;
    } 
    return j;
}

//Display table of data
void disTbl(vector<int> a, vector<int> b){
    cout << "N    Count" << endl;
    for (int k=0; k<a.size(); k++){
        if (b[k] != 0) cout << a[k] << setw(5) << b[k] << endl;
        
    }
}


//*****************************END OF PROBLEM***********************************

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//***************** Savitch 9thEd Ch7 Prob8 LetterCount ************************
//Purpose:  Grade Book program
//Inputs:   Inputs to the function here  -> Description, Range, Units
//Output:   Outputs to the function here -> Description, Range, Units
//******************************************************************************
void problem10(){
    //Declaration of Variables
    const int SIZE = 100;
    string text;
    char letters[SIZE],
         val;
    int occ[SIZE];
    
    //Input values
    cout << "Input a line of text:" << endl;
    cin.ignore();
    getline(cin,text);
    cin.clear();
    
    //Fill with all 26 letters:
    Letters(letters);
    
    //Fill in the occurrences:
    for (int i=0; i<26; i++){
        occ[i]=0;
        val = letters[i];
        occ[i]=search(text, val);
    }
    
    //Display Output
    pntTbl(text,letters,occ); 
    
    //Exit Program
}

//Fill the array with the 26 letters:
void Letters(char l[]){
    for (int i=0; i<26; i++){
        l[i]=97+i;
    }
}

//Search and fill:
int search(string t, char val){
    int count = 0;
    bool period = false;
    for (int i=0; i<t.size() && period==false; i++){
        if(t[i] == val){
            count+=1;
        }
        else if(t[i]=='.') period=true;
    }
    return count;
}

void pntTbl(string t, char l[], int o[]){
    bool period = false;
    for (int i=0; i<t.size() && period == false; i++){
        if(t[i]=='.') period=true;
        else cout << t[i];
    }
    cout << endl;
    cout << "Letter   Occurrences" << endl;
    for (int i=0; i<26; i++){
        if (o[i] > 0) cout << setw(3) << l[i] << setw(11) << o[i] << endl;
    }
    cout << endl;
}

//*****************************END OF PROBLEM***********************************

