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
    char choice;
   
   //seed random numbers ones s
    
    int a[9] = {1,2,3,4,5,0,7,8,6};
    eight_puzzle *one = new eight_puzzle();
    //one->rand_fill();
    do{
    
        one->manual_fill(a);
        one->print();
         
        cout<< "Choose another 8-puzzle?(y/n)\n";
        cin >> choice;
    }while(choice == 'n');
    
    solver *s = new solver(one);
    
    s->Uniform_Cost();
    cout << "Total moves "<< s->get_moves()<<endl;
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

