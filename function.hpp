//
//  function.hpp
//  empty
//
//  Created by Taguwa on 2022/04/21.
//

#ifndef function_h
#define function_h

#include <iostream>

using namespace std;

typedef struct row{
    int x;
    int y;
};

Grid<int32> random_question(int size){
    Grid<int32> temp(size , size , 0);
    for(int i = 0; i < size ; i++){
        for(int j = 0; j < size; j++){
            if( i == 0 || j == 0 || i == size - 1 || j == size - 1 ) temp[i][j] = 9;
            
        }
    }
    
    
    
    
    
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



Grid<int32> DFS_nextsteps(Grid<int32> a, row* pos){
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


#endif /* function_h */
