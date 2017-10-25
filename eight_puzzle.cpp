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
#include <ctime>


using namespace std;

//structure of the 8-puzzle
//   i1 | i2 | i3 
//   ____________
//   i4 | i5 | i6
//   ____________
//   i7 | i8 | i9
//////////////////////////
class eight_puzzle{
  private: 
    int puzzle_index[9] = {0,1,2,3,4,5,6,7,8}; 
    int blank = 0;
  
  public:
    eight_puzzle();
    //operators 
    void blank_up();
    void blank_down();
    void blank_left();
    void blank_right();
    
    //print function 
    void print();
    void rand_fill();
    void manual_fill();
    
    //solving solutions 
    void Uniform_Cost();
    void Misplaced_tile();
    void Manhattan_distance();
    
        
};




int main() {
    
    //seed random numbers ones 
    srand(time(0));
    
    
    eight_puzzle one;
    
    one.rand_fill();
    one.print();
    one.blank_right();
    one.print();
    
    return 0;
    
}

eight_puzzle::eight_puzzle(){
    
    
    
    
}

void eight_puzzle::blank_up(){
    if(blank > 2){
        int btemp = blank; 
        blank = blank - 3;
        int temp1 = puzzle_index[blank];
        puzzle_index[blank]= puzzle_index[btemp];
        puzzle_index[btemp] = temp1;
    
    }
}
void eight_puzzle::blank_down(){
    if(blank < 6){
        int btemp = blank; 
        blank = blank + 3;
        int temp1 = puzzle_index[blank];
        puzzle_index[blank]= puzzle_index[btemp];
        puzzle_index[btemp] = temp1;
    
    }
    
}
void eight_puzzle::blank_left(){
    if( blank != 0 && blank != 3 && blank != 6){
        int btemp = blank; 
        blank = blank - 1;
        int temp1 = puzzle_index[blank];
        puzzle_index[blank]= puzzle_index[btemp];
        puzzle_index[btemp] = temp1;
    }
    
}
void eight_puzzle::blank_right(){
    if( blank != 2 && blank != 5 && blank != 8){
        int btemp = blank; 
        blank = blank + 1;
        int temp1 = puzzle_index[blank];
        puzzle_index[blank]= puzzle_index[btemp];
        puzzle_index[btemp] = temp1;
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
        if(puzzle_index[x]==0){cout << "b" << " | "; blank = x;}
        else
        cout << puzzle_index[x] << " | ";
    }
    cout<<"\n____________"<<endl;
    cout<<"| ";
    for(int x = 3; x < 6; x++){
        if(puzzle_index[x]==0){cout << "b" << " | "; blank = x;}
        else
        cout << puzzle_index[x] << " | ";
    }
    cout<<"\n____________"<<endl;
    cout<<"| ";
    for(int x = 6; x < 9; x++){
        if(puzzle_index[x]==0){cout << "b" << " | "; blank = x;}
        else
        cout << puzzle_index[x] << " | ";
    }
    cout<<"\n____________"<<blank<<endl;
}

void eight_puzzle::rand_fill(){
    
    int r1,r2;
    int temp;
    for(int x = 0; x < 9; x++){
        r1 = rand() % 9;
        r2 = rand() % 9;
        if(puzzle_index[r1] != puzzle_index[r2]){
            temp = puzzle_index[r1];
            puzzle_index[r1] = puzzle_index[r2];
            puzzle_index[r2] = temp;
        }
        
        
   }
        
        
}
void eight_puzzle::manual_fill(){
        
}

////////////////////////////////////////////////////////
//AI Magic below here 
/////////////////////////////////////////////////////
void eight_puzzle::Uniform_Cost(){
    
    
}
void eight_puzzle::Misplaced_tile(){
    
        
}
void eight_puzzle::Manhattan_distance(){
    
    
}
    