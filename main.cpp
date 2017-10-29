/////////////////////////////////////////////////////////////////////////////////
//Lino Gonzalez Valdovinos
//861300001
//CS-170 Artificial intelegence 
//A program that solves the eight-puzzle. It will solve it using 
//1)	Uniform Cost Search 
//2)	A* with the Misplaced Tile heuristic.
//3)	A* with the Manhattan Distance heuristic.
////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <cstdlib>
#include "eight_puzzle.h"
#include "solver.h"

using namespace std;

//structure of the 8-puzzle
//   i1 | i2 | i3 
//   ____________
//   i4 | i5 | i6
//   ____________
//   i7 | i8 | i9


int main() {
    //seed random numbers ones 
    srand(time(0));
    
    //int move;
    eight_puzzle *one = new eight_puzzle();
    one->rand_fill();
    one->print();
    
    solver *s = new solver(one);
    
    s->operators(one);
    s->Uniform_Cost();
   /*
   while(1){
       
        one.print();
        
        cout << "Move blank up-1, down-2, left-3, right-4"<<endl;
        cin >> move; 
        if (move == 1 ){
            one.blank_up();
        }
        if (move == 2 ){
            one.blank_down();
        }
        if (move == 3 ){
            one.blank_left();
        }
        if (move == 4 ){
            one.blank_right();
        }
        
        if(one.check_solve()){
            cout << "Done!" << endl;
            return 0;
        }
    
        
    } */  
    return 0;
    
}

