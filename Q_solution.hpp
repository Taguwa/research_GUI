//
//  Q_solution.hpp
//  empty
//
//  Created by Taguwa on 2022/05/23.
//

#ifndef Q_solution_h
#define Q_solution_h

#include <iostream>
#include <string.h>
#include <string>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <math.h>
#include <random>
#include <regex>

#include "function.hpp"

using namespace std;

typedef struct return_data{
    Grid<int32> bod;
    int value;
    int s;
    int r;
    int r_a;
}return_data;

//1epsode みたいな感じ？
return_data Q_next_step(return_data val){
    return val;
}

//よくわかってない
void Q_Learning_Platform(int epsode , Grid<int32> board){
    cout << "Q soltution running.. | epsode : " << epsode << endl;
    
    Grid<int32> template_Q_table = board;
    
    //パラメーター
    int value = 0; //
    int s;
    int r;
    int r_a;
    
    
    return_data val = {board,value,s,r,r_a};
    
    //epsode回やる感じ？
    for(int i = 0; i < epsode ; i++){
        
        return_data next_step = Q_next_step(val);
        
    }
}

#endif /* Q_solution_h */
