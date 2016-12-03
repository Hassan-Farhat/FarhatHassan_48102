/* 
 * File:   main.cpp
 * Author: Hassan Farhat
 * Created on December 1, 2016, 6:55 PM
 * Purpose: Test out file i/o for highscores
 */

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    //Declaration of Variables
    ifstream in;
    ofstream out;
    string name, space;
    short score;
    
    //Open High Score File
    in.open("HighScores.dat");
    in>>name>>score;
    cout<<name<<"   "<< score <<endl;
    
    in.close();
    in.clear();
    out.open("HighScores.dat");
    //Change in high score
    name="Jason";
    space=" ";
    score=433;
    out<<name<<space<<score;
    out.close();
    out.clear();
    
}

