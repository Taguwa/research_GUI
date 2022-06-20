//
//  function.hpp
//  empty
//
//  Created by Taguwa on 2022/04/21.
//

#ifndef function_h
#define function_h

#include <iostream>
#include <random>
#include <queue>

using namespace std;

//座標系
typedef struct row{
    int x;
    int y;
};

//文字列（現在の状態）
String state;

//自動生成
Grid<int32> random_question(int size){
    Grid<int32> temp(size , size , 0);
    //外枠
    for(int i = 0; i < size ; i++){
        for(int j = 0; j < size; j++){
            if( i == 0 || j == 0 || i == size - 1 || j == size - 1 ) temp[i][j] = 9;
            if( i % 2 == 0 && j % 2 == 0)temp[i][j] = 9;
        }
    }
    
    //内側ランダム生成（棒倒し法）
    random_device rnd;
    mt19937 mt(rnd());
    int direct;
    //1st step
    for(int i = 2; i < 3 ; i++){
        for(int j = 2; j < size-1; j++){
            
            if(i % 2 ==0 && j % 2 == 0){
                direct = mt() % 4;
                if(direct == 0){
                    if(temp[i-1][j] == 9){direct = 1;}
                    else{temp[i-1][j] = 9;}
                }
                if(direct == 1){
                    if(temp[i+1][j] == 9){direct = 2;}
                    else{temp[i+1][j] = 9;}
                }
                if(direct == 2){
                    if(temp[i+1][j] == 9){direct = 3;}
                    else{temp[i][j-1] = 9;}
                }
                if(direct == 3){
                    temp[i][j+1] = 9;
                }
            }
        }
    }
    //2nd step
    for(int i = 4; i < size-1 ; i++){
        for(int j = 2; j < size-1; j++){
            
            if(i % 2 ==0 && j % 2 == 0){
                direct = mt() % 4;
                if(direct == 0){
                    if(temp[i][j-1] == 9){direct = 1;}
                    else{temp[i][j-1] = 9;}
                }
                if(direct == 1){
                    if(temp[i][j+1] == 9){direct = 2;}
                    else{temp[i][j+1] = 9;}
                }
                if(direct == 2){
                    if(temp[i-1][j] == 9){direct = 3;}
                    else{temp[i-1][j] = 9;}
                }
                if(direct == 3){
                    temp[i+1][j] = 9;
                }
            }
        }
    }
    temp[1][1]=2;
    temp[size-2][size-2]=3;
    
    return temp;
}

//CUI用出力
void print(Grid<int32> a){
    for(int i = 0 ; i < 11 ; i++){
        for(int j = 0 ; j < 11 ; j++){
            if(a[i][j] == 9){
                cout << "■ ";
            }else if(a[i][j] == 2){
                cout << "S ";
            }
            else if(a[i][j] == 3){
                cout << "G ";
            }
            else{
                cout << "  ";
            }
        }
        cout << endl;
    }
}

//深さ優先
Grid<int32> BFS_nextsteps(Grid<int32> a, row* pos){
    if(a[pos->y+1][pos->x] == 0){
        pos->y++;
    }
    else if(a[pos->y-1][pos->x] == 0){
        pos->y--;
    }
    else if(a[pos->y][pos->x+1] == 0){
        pos->x++;
    }
    else if(a[pos->y][pos->x-1] == 0){
        pos->x--;
    }
    
    else if(a[pos->y+1][pos->x] == 1){
        a[pos->y][pos->x] = 99;
        pos->y++;
    }
    else if(a[pos->y-1][pos->x] == 1){
        a[pos->y][pos->x] = 99;
        pos->y--;
    }
    else if(a[pos->y][pos->x+1] == 1){
        a[pos->y][pos->x] = 99;
        pos->x++;
    }
    else if(a[pos->y][pos->x-1] == 1){
        a[pos->y][pos->x] = 99;
        pos->x--;
    }
    
    a[pos->y][pos->x] = 1;
    cout << pos->y << pos->x <<endl;
    return a;
}

//深さ優先
queue<row> que;
Grid<int32> DFS_nextsteps(Grid<int32> a, row* pos){
    
    if(a[pos->y+1][pos->x] == 0){
        que.push({pos->x,pos->y+1});
    }
    if(a[pos->y-1][pos->x] == 0){
        que.push({pos->x,pos->y-1});
    }
    if(a[pos->y][pos->x+1] == 0){
        que.push({pos->x+1,pos->y});
    }
    if(a[pos->y][pos->x-1] == 0){
        que.push({pos->x-1,pos->y});
    }
    
    row front = que.front();
    pos->x = front.x;
    pos->y = front.y;
    que.pop();
    
    a[pos->y][pos->x] = 1;
    cout << pos->y << pos->x <<endl;
    return a;
}


#endif /* function_h */
