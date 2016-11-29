/*
 * File:   main.cpp
 * Author: Hassan Farhat
 * Created on November 25, 2016, 3:50 PM
 * Purpose
 */

#include <iostream>   //Input/Output objects
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

const int MAPCOL=100;

void crtmap(char[][MAPCOL]);
char spType(int);

int main(int argc, char** argv) {
    srand(static_cast<unsigned int> (time(0)));
    const int MAPROW=100;
    char map[MAPROW][MAPROW], pmap[MAPROW][MAPROW];
    crtmap(map);
    string move;
    int prow=6, pcol=4;
    int spawn;
    pmap[prow][pcol]='P';
    do{
        for (int i=0; i<7; i++){
            for (int k=0; k<9; k++){
                if(map[i][k]=='-' || map[i][k]=='*' || map[i][k]=='#')map[i][k] = spType(spawn);
            }
        }
        for (int i=0; i<7; i++){
            for (int k=0; k<9; k++){
                if (i!=prow || k!=pcol) pmap[i][k]= map[i][k];
            }
        }
        for (int i=0; i<7; i++){
            for (int k=0; k<9; k++){
                cout << pmap[i][k];
                if(k==8) cout<<endl;
            }
        }
        
        cout<<"Input the direction of your turn (up,left,right)"<<endl;
        cin>>move;
        //Determine player location on map
        if (move == "up" || move == "Up") prow -= 1;
        else if (move == "right" || move == "Right") pcol += 1;
        else if (move == "left" || move == "Left") pcol -= 1;
        pmap[prow][pcol] = 'P';
    }while (move!="end");
    return 0;
}

void crtmap(char map[][MAPCOL]){
    for (int i=0; i<7; i++){
        for (int k=0; k<9; k++){
            if(i==0 && (k==0 || k==2 || k==6 || k==8)) map[i][k]='|';
            else if(i==1&&(k==0 || k==2 || k==6 || k==8)) map[i][k]='|';
            else if(i==2&&(k==0 || k==4 || k==8)) map[i][k]='|';
            else if(i==3&&(k==0 || k==2 || k==6 || k==8)) map[i][k]='|';
            else if(i==4&&(k==0 || k==2 || k==4 || k==6 || k==8))map[i][k]='|';
            else if(i==5&&(k==0 || k==8)) map[i][k]='|';
            else if(i==6&&(k==0 || k==3 || k==5 || k==8)) map[i][k]='|';
            else if(i==0&&k==4)map[i][k]='B';
            else if(i==6&&k==4)map[i][k]='C';
            else map[i][k]='-';
        }
    }
}

char spType(int spawn){
   spawn = rand()%3;
   if (spawn == 0) return '-';
   else if (spawn == 1) return '*';
   else if (spawn == 2) return '#'; 
}