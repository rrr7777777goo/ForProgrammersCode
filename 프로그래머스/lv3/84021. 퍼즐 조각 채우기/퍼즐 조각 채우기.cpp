#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int c;
bool isAlreadyUsed[2500];
int leng;
bool isBlock[2500][50][50];
int sizeBlock[2500];

int solution(vector<vector<int>> game_board, vector<vector<int>> table) {
    leng = table.size();
    
    for(int y = 0; y < table.size(); y++)
    {
        for(int x = 0; x < table[y].size(); x++)
        {  
            if(table[y][x])
            {
                table[y][x] = false; ++sizeBlock[c];
                int minY = y, minX = x;
                vector<int> restore_Y, restore_X; restore_Y.push_back(y); restore_X.push_back(x);
                queue<int> qu_Y, qu_X; qu_Y.push(y); qu_X.push(x);
                
                while(!qu_Y.empty())
                {
                    queue<int> temp_qu_Y, temp_qu_X;
                    
                    while(!qu_Y.empty())
                    {
                        int y_Q = qu_Y.front(), x_Q = qu_X.front(); qu_Y.pop(); qu_X.pop();
                        
                        if(y_Q >= 1) // 상
                        {
                            if(table[y_Q-1][x_Q])
                            {
                                if((y_Q - 1) < minY) minY = (y_Q - 1);
                                table[y_Q-1][x_Q] = false; ++sizeBlock[c]; 
                                restore_Y.push_back(y_Q-1); restore_X.push_back(x_Q);
                                temp_qu_Y.push(y_Q-1); temp_qu_X.push(x_Q);
                            }
                        }
                        if (y_Q <= (leng-2)) // 하
                        {
                            if(table[y_Q+1][x_Q])
                            {
                                table[y_Q+1][x_Q] = false; ++sizeBlock[c]; 
                                restore_Y.push_back(y_Q+1); restore_X.push_back(x_Q);
                                temp_qu_Y.push(y_Q+1); temp_qu_X.push(x_Q);
                            }                            
                        }
                        if(x_Q >= 1) // 좌
                        {
                            if(table[y_Q][x_Q-1])
                            {
                                if((x_Q - 1) < minX) minX = (x_Q - 1);
                                table[y_Q][x_Q-1] = false; ++sizeBlock[c]; 
                                restore_Y.push_back(y_Q); restore_X.push_back(x_Q-1);
                                temp_qu_Y.push(y_Q); temp_qu_X.push(x_Q-1);
                            }                                 
                        }
                        if (x_Q <= (leng-2)) // 우
                        {
                            if(table[y_Q][x_Q+1])
                            {
                                table[y_Q][x_Q+1] = false; ++sizeBlock[c]; 
                                restore_Y.push_back(y_Q); restore_X.push_back(x_Q+1);
                                temp_qu_Y.push(y_Q); temp_qu_X.push(x_Q+1);
                            }                               
                        }
                    }
                    
                    qu_Y = temp_qu_Y; qu_X = temp_qu_X;
                }
                
                for(int i = 0; i < restore_Y.size(); i++)
                { 
                    restore_Y[i] -= minY; restore_X[i] -= minX;
                    isBlock[c][restore_Y[i]][restore_X[i]] = true;
                }
                
                ++c; 
            }
        }
    }
    
    int answer = 0;
    
    for(int y = 0; y < game_board.size(); y++)
    {
        for(int x = 0; x < game_board[0].size(); x++)
        {
            if(!game_board[y][x])
            {
                game_board[y][x] = true;
                int minY = y, minX = x, maxY = y, maxX = x;
                vector<int> restore_Y, restore_X; restore_Y.push_back(y); restore_X.push_back(x);
                queue<int> qu_Y, qu_X; qu_Y.push(y); qu_X.push(x);
                
                while(!qu_Y.empty())
                {
                    queue<int> temp_qu_Y, temp_qu_X;
                    
                    while(!qu_Y.empty())
                    {
                        int y_Q = qu_Y.front(), x_Q = qu_X.front(); qu_Y.pop(); qu_X.pop();
                        
                        if(y_Q >= 1) // 상
                        {
                            if(!game_board[y_Q-1][x_Q])
                            {
                                if((y_Q - 1) < minY) minY = (y_Q - 1);
                                game_board[y_Q-1][x_Q] = true;
                                restore_Y.push_back(y_Q-1); restore_X.push_back(x_Q);
                                temp_qu_Y.push(y_Q-1); temp_qu_X.push(x_Q);
                            }
                        }
                        if (y_Q <= (leng-2)) // 하
                        {
                            if(!game_board[y_Q+1][x_Q])
                            {
                                if((y_Q + 1) > maxY) maxY = (y_Q + 1);
                                game_board[y_Q+1][x_Q] = true;
                                restore_Y.push_back(y_Q+1); restore_X.push_back(x_Q);
                                temp_qu_Y.push(y_Q+1); temp_qu_X.push(x_Q);
                            }                            
                        }
                        if(x_Q >= 1) // 좌
                        {
                            if(!game_board[y_Q][x_Q-1])
                            {
                                if((x_Q - 1) < minX) minX = (x_Q - 1);
                                game_board[y_Q][x_Q-1] = true;
                                restore_Y.push_back(y_Q); restore_X.push_back(x_Q-1);
                                temp_qu_Y.push(y_Q); temp_qu_X.push(x_Q-1);
                            }                                 
                        }
                        if (x_Q <= (leng-2)) // 우
                        {
                            if(!game_board[y_Q][x_Q+1])
                            {
                                if((x_Q + 1) > maxX) maxX = (x_Q + 1);
                                game_board[y_Q][x_Q+1] = true;
                                restore_Y.push_back(y_Q); restore_X.push_back(x_Q+1);
                                temp_qu_Y.push(y_Q); temp_qu_X.push(x_Q+1);
                            }
                        }
                    }
                    
                    qu_Y = temp_qu_Y; qu_X = temp_qu_X; 
                }

                cout << endl;
                
                for(int i = 0; i < restore_Y.size(); i++)
                { 
                    restore_Y[i] -= minY; restore_X[i] -= minX;
                }
                int lY = maxY - minY + 1, lX = maxX - minX + 1;
            
                int ssiz = lY < lX ? lX : lY;
                
                int rotcount = 0;
                while(true)
                {
                    bool isFind = false;
                    for(int cCc = 0; cCc < c; cCc++)
                    {
                        if(isAlreadyUsed[cCc]) continue;
                        
                        bool isWrong = false;
                        if(sizeBlock[cCc] == restore_Y.size())
                        {
                           for(int vi = 0; vi < restore_Y.size(); vi++)
                           {
                               if(!isBlock[cCc][restore_Y[vi]][restore_X[vi]])
                               {
                                   isWrong = true; break;
                               }
                           }
                        }
                        else isWrong = true;
                        if(!isWrong)
                        {
                            isAlreadyUsed[cCc] = true;
                            answer += restore_Y.size();
                            isFind = true;
                            break;
                        }
                    }
                    if(isFind) break;
                    
                    ++rotcount;
                    if(rotcount > 3) break;
                    else
                    {
                       int minY2 = 51, minX2 = 51;
                       for(int vi = 0; vi < restore_Y.size(); vi++)
                       {
                           int ttY = restore_X[vi];
                           int ttX = ssiz - restore_Y[vi] - 1;
                           restore_Y[vi] = ttY;
                           if(minY2 > ttY) minY2 = ttY;
                           restore_X[vi] = ttX;
                           if(minX2 > ttX) minX2 = ttX;
                       }
                        
                       for(int vi = 0; vi < restore_Y.size(); vi++)
                       {
                           restore_Y[vi] -= minY2;
                           restore_X[vi] -= minX2;
                       }
                    }
                }
            }    
        }
    }    
    
    return answer;
}