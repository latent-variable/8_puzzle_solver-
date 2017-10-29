#ifndef EIGHT_PUZZLE_H
#define EIGHT_PUZZLE_H



//////////////////////////
class eight_puzzle{
  private: 
    int puzzle[9] = {0,1,2,3,4,5,6,7,8}; 
    int blank = 0;
    
  public:
    eight_puzzle(){};
    eight_puzzle(int p[] );
    //operators 
    int get_blank();
    int *get_puzzle();
    void blank_up();
    void blank_down();
    void blank_left();
    void blank_right();
    
    //print function 
    void print();
    void rand_fill();
    void manual_fill();
    
    //check for solution
    bool check_solve();
        
};

#endif