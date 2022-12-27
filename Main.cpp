# include <Siv3D.hpp> // OpenSiv3D v0.6.3

#include <iostream>
#include <fstream>
#include <cstdio>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <sstream>
//#include <opencv2/opencv.hpp>

#include <string.h>
#include <string>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <math.h>
#include <random>
#include <regex>

//標準追加関数用
#include "function.hpp"
//Qsolution実装用
#include "Q_solution.hpp"

using namespace std;


void Main()
{

    //scene settings
    Window::SetStyle(WindowStyle::Sizable);
    Window::Resize(1200,800);
    Scene::SetBackground(Color(200, 200, 200));//背景色設定
     const Font font(30, Typeface::Black);
    
    //void main()
    row pos = {1,1};
    int size = 21;
    state = U"R : Searching...";
    String size_of_maze = U"maze size : {} * {} "_fmt(Format(size),Format(size));
    String Location = U"pos : ( {} , {} ) "_fmt(Format(pos.y),Format(pos.x));
   
    //壁9（黒） スタート2 ゴール3 何もなし0（白） 探索済1（緑） エージェント別変数（水色）
    Grid<int32> grid = /*{{9,9,9,9,9,9,9},
        {9,2,9,0,0,0,9},
       {9,0,9,0,9,0,9},
        {9,0,9,0,9,9,9},
        {9,0,0,0,0,0,9},
        {9,9,0,9,9,0,9},
        {9,0,0,0,9,3,9},
        {9,9,9,9,9,9,9}
    };*/
      {{9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
        {9,2,9,0,0,0,0,0,0,0,0,0,9,0,9},
        {9,0,9,9,9,9,9,9,9,9,9,0,9,0,9},
        {9,0,0,0,0,9,0,0,0,0,0,0,0,0,9},
        {9,0,9,9,9,9,0,9,9,9,9,9,9,9,9},
        {9,0,0,0,0,9,0,9,0,0,0,0,0,0,9},
        {9,9,0,9,0,9,0,9,9,9,0,9,0,9,9},
        {9,9,0,9,0,9,0,0,0,0,0,9,0,0,9},
        {9,9,0,9,0,9,9,9,9,9,9,9,9,0,9},
        {9,9,0,9,0,9,0,0,0,0,0,0,0,0,9},
        {9,9,0,9,0,0,0,9,9,9,9,9,9,0,9},
        {9,0,0,9,9,0,9,9,0,0,0,0,0,0,9},
        {9,9,9,9,9,0,9,9,0,9,9,9,9,9,9},
        {9,0,0,0,0,0,0,9,0,0,0,0,0,3,9},
        {9,9,9,9,9,9,9,9,9,9,9,9,9,9,9}};
    
  
    
    //GUI LOOP
    while (System::Update())
    {
        //
        //
        //　描画設定など
        //
        //
        
        font(size_of_maze).draw(760, 450, ColorF(0.2));
        
        font(state).draw(760, 50, ColorF(0.2));
        
        font(Location).draw(760, 100, ColorF(0.2));
        
        Cursor::RequestStyle(CursorStyle::Hand);
        
        //
        //
        //  各種機能（主にボタン）
        //
        //

        //メッセージ表示
        Location = U"Location : ( {} , {} ) "_fmt(Format(pos.y),Format(pos.x));
        if(pos.y == size - 2 && pos.x == size - 2) state =  U"R : Complete";
        
        //BFSで1step進む関数を動かすボタン。
        if(SimpleGUI::Button(U"BFS next steps", Vec2(760, 150))){
                grid = BFS_nextsteps(grid,&pos);
            /*const double t = Scene::Time();
            while(t < Scene::Time()){
                }*/
              }
        
        //DFSで1step進む関数を動かすボタン。
        if(SimpleGUI::Button(U"DFS next steps", Vec2(760, 200))){
            grid = DFS_nextsteps(grid,&pos);
        }
        
        //エージェントの位置を初期位置に
        if(SimpleGUI::Button(U"reset pos", Vec2(760, 250))){
            pos = {1,1};
        }
        
        //function random_questionを実行
        if(SimpleGUI::Button(U"random solution", Vec2(760, 300))){
            grid = random_question(size);
        }
        
        //
        //
        //  Q
        //
        //
        
        if(SimpleGUI::Button(U"test Q_SOLUTION", Vec2(760, 400))){
            
            Q_Learning_Platform(10, grid, size);
            state = U"R : Q ";
        }
        
        //
        //
        //  迷路の描画
        //
        //
        
        for (int y = 0 ; y < int(grid.height()) ; y++){
            for (int x = 0 ; x < int(grid.height()) ; x++)
            {
                if(grid[y][x] == 9){
                    Rect(x*30, y*30, 100).draw(Palette::Black);
                }
                else if(grid[y][x] == 0){
                    Rect(x*30, y*30, 100).draw(Palette::White);
                }
                else if(grid[y][x] == 2){
                    Rect(x*30, y*30, 100).draw(Palette::Red);
                }
                else if(grid[y][x] == 3){
                    Rect(x*30, y*30, 100).draw(Palette::Blue);
                }
                else if(grid[y][x] == 1 || grid[y][x] == 99){
                    Rect(x*30, y*30, 100).draw(Palette::Green);
                }
                if(y == pos.y && x == pos.x) Rect(x*30, y*30, 100).draw(ColorF(0.3, 0.6, 1.0));
            }
        }
        
        //while() end
        
    }
    
    //Main() end
    
}


