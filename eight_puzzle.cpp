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
///////all four operators for the blank tile//////////////////////
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
//////////////////////////////////////////////
// pretty print 
// ____________
// | 5 | 8 | 6 | 
// ____________
// | 9 | 3 | 9 | 
// ____________
// | 2 | 8 | 4 | 
// ____________b  
// where b is the position of the blank tile
void eight_puzzle::print(){
   
        
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
////////////////////////////////////////////////////////////////
//Generates a Random puzzle by randomly selecting 1/4 operators
//for a random number of times from 5 to 31 the diameter 
void eight_puzzle::rand_fill(){
    
    srand(time(0));
    
    int r1,r2;
    r2 = rand() % 32 + 5;
    for(int x = 0; x <= r2; x++){
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
/////////// depth for this problem is the cost functiong (n)///////////////////////////
void eight_puzzle::set_depth(int d){
    depth = d;
}
int eight_puzzle::get_depth(){
    return depth;
}
////////////////////easy to calcute misplaced_title//////////////////////////////////
void eight_puzzle::set_heuristic_misplaced_tile(){
    for(int i = 1; i < 10; i++ ){
        if (puzzle[i-1] == 0) continue;
        if( i != puzzle[i-1]) heuristic++;
    }
}////////////////////////////////////////////////////////////////////
//Not gonna lie im pretty proud of this one. Took so effort
//              Lino's Algorithm for manhantan distance
//Calcultes the manhattan distance of an 8-puzzle in a array 
//Let the blank = 9;
//for (int i = 1; i <= 9; i++)
//x = absolute(Puzzle[ i - 1 ] - i)   // |subtract the value in the array by the index|
//Heuristic += (x/3)  + x % 3           //calculate huristic 
void eight_puzzle::set_heuristic_manhattan_distance(){
    int x, z, y;
    for(int i = 1; i <= 9; i++ ){
         if (puzzle[i-1] == 0){
              continue;
         }else{ y = puzzle[i-1];}
         //only 4 exeptions to this rule out of 81 possibilities that I found so far
         if (i == 3 && puzzle[i-1] == 4 ){
             heuristic += 3;
             continue;
         }
         if(i == 6 && puzzle[i-1] == 7){
             heuristic += 3;
             continue;
         }
         if(i == 3 && puzzle[i-1] == 7){
             heuristic += 4;
             continue;
         };
         if(i == 7 && puzzle[i-1] == 3){
             heuristic += 4;
             continue;
         };
         
         z = abs(y - i); 
         x = z / 3;             //notice interger division always uses a floor function 
         x = x + (z%3);
         heuristic += x;
    }
   ;
}
int eight_puzzle::get_heuristic(){
    return heuristic;
}
int eight_puzzle::get_A_star(){
    //by definition A*
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