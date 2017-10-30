#ifndef SOLVER_H
#define SOLVER_H
/*
#include <iostream>
#include <cstdlib>

#include "eight_puzzle.h"
*/
#include <queue>
#include <vector>

using namespace std;
class eight_puzzle;

class solver{
    public:
        solver();
        solver(eight_puzzle*);
        
        void operators(eight_puzzle*);
        bool check_tree(eight_puzzle*);
        bool compare_puzzle(int*,int*);
        int get_moves();
        
        
        //solving solutions 
        void Uniform_Cost();
        void Misplaced_tile();
        void Manhattan_distance();
    
    private:
    
        int moves = 0;
        queue<eight_puzzle*> puzzle_queue;
        vector<eight_puzzle*> puzzle_tree;
    
};

#endif