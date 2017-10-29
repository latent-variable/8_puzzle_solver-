#include <iostream>
#include <cstdlib>
#include "eight_puzzle.h"

using namespace std;

eight_puzzle::eight_puzzle(int p[9]){
    for(int i = 0; i < 9; i++){
        if(p[i] == 0) blank = i;
        puzzle[i] = p[i];
    }
    
}

void eight_puzzle::blank_up(){
    if(blank > 2){
        int btemp = blank; 
        blank = blank - 3;
        int temp1 = puzzle[blank];
        puzzle[blank]= puzzle[btemp];
        puzzle[btemp] = temp1;
    
    }
}
void eight_puzzle::blank_down(){
    if(blank < 6){
        int btemp = blank; 
        blank = blank + 3;
        int temp1 = puzzle[blank];
        puzzle[blank]= puzzle[btemp];
        puzzle[btemp] = temp1;
    
    }
    
}
void eight_puzzle::blank_left(){
    if( blank != 0 && blank != 3 && blank != 6){
        int btemp = blank; 
        blank = blank - 1;
        int temp1 = puzzle[blank];
        puzzle[blank]= puzzle[btemp];
        puzzle[btemp] = temp1;
    }
    
}
void eight_puzzle::blank_right(){
    if( blank != 2 && blank != 5 && blank != 8){
        int btemp = blank; 
        blank = blank + 1;
        int temp1 = puzzle[blank];
        puzzle[blank]= puzzle[btemp];
        puzzle[btemp] = temp1;
    }
}

void eight_puzzle::print(){
    //pretty print 
    // ____________
    // | 5 | 8 | 6 | 
    // ____________
    // | 9 | 3 | 9 | 
    // ____________
    // | 2 | 8 | 4 | 
    // ____________b
        
    cout<<"\n____________"<<endl;
    cout<<"| ";
    for(int x = 0; x < 3; x++){
        if(puzzle[x]==0){cout << "b" << " | "; blank = x;}
        else
        cout << puzzle[x] << " | ";
    }
    cout<<"\n____________"<<endl;
    cout<<"| ";
    for(int x = 3; x < 6; x++){
        if(puzzle[x]==0){cout << "b" << " | "; blank = x;}
        else
        cout << puzzle[x] << " | ";
    }
    cout<<"\n____________"<<endl;
    cout<<"| ";
    for(int x = 6; x < 9; x++){
        if(puzzle[x]==0){cout << "b" << " | "; blank = x;}
        else
        cout << puzzle[x] << " | ";
    }
    cout<<"\n____________"<<blank<<endl;
}

void eight_puzzle::rand_fill(){
    
    int r1,r2;
    int temp;
    for(int x = 0; x < 9; x++){
        r1 = rand() % 9;
        r2 = rand() % 9;
        if(puzzle[r1] != puzzle[r2]){
            temp = puzzle[r1];
            puzzle[r1] = puzzle[r2];
            puzzle[r2] = temp;
        }
        
        
   }
        
}

 int eight_puzzle::get_blank(){
     return blank;
     
 }
 int * eight_puzzle::get_puzzle(){
     return puzzle;
 }
void eight_puzzle::manual_fill(){
        
}


////////////////////////////////////////////////////
//Well we want to know when we are done! Right?
///////////////////////////////////////////////////
bool eight_puzzle::check_solve(){
    int val = 1;
    for(int i = 0; i < 8; i++){
        if(puzzle[i] != val) return false;
        val++;
    }
    
    return true; 
}