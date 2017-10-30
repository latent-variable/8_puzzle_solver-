#include <iostream>
#include <cstdlib>
#include <queue>
#include <vector>
#include "eight_puzzle.h"
#include "solver.h"


using namespace std;


//*********************************************************
////////////////////////////////////////////////////////////
//solver class stuff
///////////////////////////////////////////////////////////
solver::solver(eight_puzzle* p){
    puzzle_queue.push(p);
    puzzle_tree.push_back(p);
    
}
void solver::operators(eight_puzzle *p){
    
    bool test_tree = false;
    int blank = p->get_blank();
    
    if(blank > 2){
        eight_puzzle *a =new eight_puzzle(p->get_puzzle());
        a->blank_up();
        
        test_tree = check_tree(a);
        if(test_tree == true ){
            puzzle_queue.push(a);
            puzzle_tree.push_back(a);
        }
    }    
    if(blank < 6){
        eight_puzzle *b = new eight_puzzle(p->get_puzzle());
        b->blank_down();
       
        test_tree = check_tree(b);
        if(test_tree == true ){
            puzzle_queue.push(b);
            puzzle_tree.push_back(b);
        }
    
    }
    if( blank != 0 && blank != 3 && blank != 6){
        eight_puzzle *c = new eight_puzzle(p->get_puzzle());
        c->blank_left();
        
        test_tree = check_tree(c);
        if(test_tree == true ){
            puzzle_queue.push(c);
            puzzle_tree.push_back(c);
        }
    
    }
    if( blank != 2 && blank != 5 && blank != 8){
         eight_puzzle *d = new eight_puzzle(p->get_puzzle());
         d->blank_right();

         test_tree = check_tree(d);
         if(test_tree == true ){
            //d->print();
            puzzle_queue.push(d);
            puzzle_tree.push_back(d);
        }
    
    }
}
////////////////////////////////////////////////////////
//flag mess below beware
/////////////////////////////////////////////
bool solver::check_tree(eight_puzzle* p){
   
    bool flag = false;
    for(unsigned i = 0; i < puzzle_tree.size(); i++){
            flag = compare_puzzle(p->get_puzzle(),puzzle_tree[i]->get_puzzle());
            if(flag == true){
                return false;
            }
    }
    return true;
}
bool solver::compare_puzzle(int*a,int*b){
    for(int j = 0 ; j < 9; j++)
            {
                if ( a[j] != b[j] ) 
                    return false;
            }
    return true;
}
 int solver::get_moves(){
     
     return moves;
     
 }
/////////////////////////////////////////////////////
//AI Magic below here 
/////////////////////////////////////////////////////
void solver::Uniform_Cost(){
    moves = 0;
/* 
function general-search(problem, QUEUEING-FUNCTION)  
    nodes = MAKE-QUEUE(MAKE-NODE(problem.INITIAL-STATE)) 
    loop do
    if EMPTY(nodes) then return "failure" 
        node = REMOVE-FRONT(nodes) 
    if problem.GOAL-TEST(node.STATE) succeeds then return node
        nodes = QUEUEING-FUNCTION(nodes, EXPAND(node, problem.OPERATORS))  
 end
*/
    bool solved = false;
    while(solved == false){
        if(puzzle_queue.empty()){
            cout << "You are a failure!\n";
            break;
        }else{
            eight_puzzle * p = puzzle_queue.front();
            puzzle_queue.pop();
            moves++;
            p->print();
            solved = p->check_solve();
            
            if(solved == true){
                cout << "Yeahh!\n";
                break;
            }
            operators(p);
        }
    }
    
}
void solver::Misplaced_tile(){
    
        
}
void solver::Manhattan_distance(){
    
    
}
