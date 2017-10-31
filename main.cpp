/////////////////////////////////////////////////////////////////////////////////
//Lino Gonzalez Valdovinos
//861300001
//CS-170 Artificial intelligence 
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
    
    
    
   
   
    cout << "\nWelcome to Lino Gonzalez Valdovinos 8-puzzle solver.\n";
    
    do{
        int a[9];
        eight_puzzle *one = new eight_puzzle();     //8-puzzle object pointer to evaluate
        solver *s = new solver(one);               //solver object to solves puzzle 
        int choice, move;
        cout << "Type “1” to use a random generated puzzle, or “2” to enter your own puzzle.\n";
        cin >> choice;
        
        switch(choice){
            case 1:
                do{
                    one->rand_fill();
                    one->print();
                    cout<< "Choose another 8-puzzle?(1-yes/0-no)\n";
                    cin >> choice;
                }while(choice == 1);
                break;
                
            case 2:
                cout << "Enter your puzzle, use a zero to represent the blank\n";
                cout << "Enter the first row, use space or tabs between numbers\n";
                cin >> a[0] >> a[1] >> a[2];
                cout << "Enter the second row, use space or tabs between numbers\n";
                cin >> a[3] >> a[4] >> a[5];
                cout << "Enter the third row, use space or tabs between numbers\n";
                cin >> a[6] >> a[7] >> a[8];
                one->manual_fill(a);
                break;
            
        }
        cout << "Enter your choice of algorithm.\n";
        cout << "1.	Uniform Cost Search\n";
        cout << "2.	A* with the Misplaced Tile heuristic.\n";
        cout << "3.	A* with the Manhattan distance heuristic.\n";
        cout << "4.	solve yourself.\n";
        cin >> choice;
        
        switch(choice){
            case 1:
                cout<<"Initial state.\n";
                one->print();
                s->Uniform_Cost();
                break;
            case 2:
                cout<<"Initial state.\n";
                one->print();
                s->Misplaced_tile();
                break;
            case 3:
                cout<<"Initial state.\n";
                one->print();
                s->Manhattan_distance();
                break;
            case 4:
                int counter = 0; 
                while(1){
                        
                        one->print();
                        
                        cout << "Move blank up-1, down-2, left-3, right-4"<<endl;
                        cin >> move;
                        counter++;
                        if (move == 1 ){
                            one->blank_up();
                        }
                        if (move == 2 ){
                            one->blank_down();
                        }
                        if (move == 3 ){
                            one->blank_left();
                        }
                        if (move == 4 ){
                            one->blank_right();
                        }
                        
                        if(one->check_solve()){
                            cout << "Solved in "<< counter<< "moves!" << endl;
                            return 0;
                        }
                }
                break;
        }
        cout << "To solve this problem the search algorithm expanded a total of " << s->get_moves()<< " nodes.\n";
        cout << "The maximum number of nodes in the queue at any one time was " <<s->get_queue_size()<<".\n";
        cout << "The depth of the goal node was " <<s->get_final_depth()<<".\n";
    }while(1);
   
    return 0;
    
}

