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
    cout<<"\n____________"<<blank+1<<endl;
}

void eight_puzzle::rand_fill(){
    
    srand(time(0));
    
    int r1,r2;
    r2 = rand() % 10;
    for(int x = 0; x < r2; x++){
        r1 = rand() % 4;
        
        if(r1 == 0) blank_down();
        if(r1 == 1) blank_up();
        if(r1 == 2) blank_left();
        if(r1 == 3) blank_right();
   }
        
}

 int eight_puzzle::get_blank(){
     return blank;
     
 }
 int * eight_puzzle::get_puzzle(){
     return puzzle;
 }
void eight_puzzle::manual_fill(int p[9]){
    for(int i = 0; i < 9; i++){
        if(p[i] == 0) blank = i;
        puzzle[i] = p[i];
    }
        
}
////////////H
void eight_puzzle::set_depth(int d){
    depth = d;
}
int eight_puzzle::get_depth(){
    return depth;
}
void eight_puzzle::set_heuristic_misplaced_tile(){
    for(int i = 1; i < 10; i++ ){
        if( i != puzzle[i-1]) heuristic++;
    }
}
void eight_puzzle::set_heuristic_manhattan_distance(){
    int x, z, y;
    for(int i = 1; i <= 9; i++ ){
         if (puzzle[i-1] == 0) y = 9;
         else y = puzzle[i-1];
         if (i == 3 && puzzle[i-1] == 4 ){
             heuristic += 3;
             continue;
         }
         if(i == 6 && puzzle[i-1] == 7){
             heuristic += 3;
             continue;
         };
         z = abs(y - i); 
         x =   z / 3;
         x = x + z % 3;
         heuristic += x;
    }
}
int eight_puzzle::get_heuristic(){
    return heuristic;
}
int eight_puzzle::get_A_star(){
    
    return heuristic + depth;
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