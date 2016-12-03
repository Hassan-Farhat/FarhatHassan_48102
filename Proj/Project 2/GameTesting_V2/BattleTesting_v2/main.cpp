/* 
 * File:   main.cpp
 * Author: Hassan Farhat
 * Created on November 30, 2016, 8:44 AM
 * Purpose: test out how the battle system of the game will function.
 */

#include <cstdlib>
#include <iostream>
#include <ctime>
#include <iomanip>

using namespace std;
void roll(int[], int, int[], int, int[], int, int[], int);
void sort(int[], int);
void pntroll(int[], int, int[], int, int[], int, int[], int);
int  fight(int[], int, int[], int, int &);
int  sfight(int[], int, int[], int, int &);

int main(int argc, char** argv) {
    //Set random number seed
    srand(static_cast<unsigned int> (time(0)));
    
    //Declare variables
    const int SIZE = 100;
    int spDice[SIZE], pDice[SIZE], scDice[SIZE], cDice[SIZE];
    int sn=3,n=4,sm=2,m=3;
    int cWins,pWins,scWins,spWins;
    
    //Roll the dice:
    roll(spDice,sn,pDice,n,scDice,sm,cDice,m);
    sort(spDice,sn);
    sort(pDice,n);
    sort(scDice,sm);
    sort(cDice,m);
    pWins = fight(pDice,n,cDice,m,cWins);
    spWins = sfight(spDice,sn,scDice,sm,scWins);
    pntroll(spDice,sn,pDice,n,scDice,sm,cDice,m);
    cout<<pWins<<setw(2)<<cWins<<endl;
    if (pWins>cWins) cout<<"You attack"<<endl;
    else if (pWins<cWins) cout<<"The monster successfully attacks"<<endl;
    else cout<<"You both hit each other"<<endl;
    cout<<spWins<<setw(2)<<scWins<<endl;
    return 0;
}

int  fight(int pD[],int n,int cD[],int m,int &cWins){
    int pWins=0;
    cWins=0;
    for (int i=0; i<m; i++){
        if (pD[i]>cD[i]) pWins+=1;
        else if (pD[i]<cD[i]) cWins+=1;
        else{
            pWins+=1;
            cWins+=1;
        }
    }
    return pWins;
}

int  sfight(int spD[],int sn,int scD[],int sm,int & scWins){
    int spWins=0;
    scWins=0;
    for (int i=0; i<sm; i++){
        if (spD[i]>scD[i]) spWins+=1;
        else if (spD[i]<scD[i]) scWins+=1;
        else{
            spWins+=1;
            scWins+=1;
        }
    }
    return spWins;
}

void roll(int spD[],int sn,int pD[],int n,int scD[],int sm,int cD[],int m){
    for (int i=0; i<sn; i++)spD[i]=rand()%12+1;
    for (int i=0; i<n; i++)pD[i]=rand()%12+1;
    for (int i=0; i<sm; i++)scD[i]=rand()%12+1;
    for (int i=0; i<m; i++)cD[i]=rand()%12+1;
}

void sort(int a[],int size){
    for(int i=0;i<size-1;i++){
        for(int j=i+1;j<size;j++){
            if(a[i]<a[j]){
                a[i]=a[i]^a[j];
                a[j]=a[i]^a[j];
                a[i]=a[i]^a[j];
            }
        }
    }
}

void pntroll(int spD[],int sn,int pD[],int n,int scD[],int sm,int cD[],int m){
    cout <<"NORMAL DICE   SPECIAL DICE" << endl;
    for (int i=0; i<n-1; i++)cout<<setw(3)<<pD[i];
    cout << "        ";
    for (int i=0; i<sn-1; i++)cout<<setw(3)<<spD[i];
    cout << endl;
    for (int i=0; i<m; i++)cout<<setw(3)<<cD[i];
    cout << "        ";
    for (int i=0; i<sm; i++)cout<<setw(3)<<scD[i];
    cout<<endl;
}