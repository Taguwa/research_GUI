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
}return_data;


void Q_Learning_Platform(int epsode , Grid<int32> board ,int size){
    
    // 何回ゴールするか
    int EPISODE_MAX = 1000;
    // ゴールまでの打ち切りステップ数
    int STEP_MAX = 3000;
    //学習率 0~1
    int alpha = 0.3;
    //割引率
    int gamma = 0.7;
    //Qtable
    vector<vector<int>> Q_table(size , vector<int>(size));
    
    
    
    //epsode回実装
    for(int i = 0; i < epsode ; i++){
        cout << "Q soltution running.. | epsode : " << epsode << endl;
        
    }
}

//処理用関数

//最良一番いいのを出す
int select_best_action(vector<vector<int>> Q_table, row pos){
    return 0;
}

//行動決定関数 ... 一定の確率で、ベストでない動きをする
void select_action(){
    
}


#endif /* Q_solution_h */
