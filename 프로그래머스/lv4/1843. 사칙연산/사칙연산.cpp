#include <vector>
#include <string>
#include <iostream>
using namespace std;

bool isMax[202][202], isMin[202][202];
int maxVal[202][202], minVal[202][202];

vector<string> ys;

int dp(int sta, int en, bool isFindMax)
{
    int retVal = isFindMax ? -10000000: 10000000;
    
    if(sta == en)
    {
        retVal = stoi(ys[sta]);
        maxVal[sta][en] = retVal; minVal[sta][en] = retVal;
        isMax[sta][en] = true; isMin[sta][en] = true;
    }
    else
    {
        for(int i = sta+1; i <= en; i += 2)
        {
            int y1, y2;
            if(ys[i].compare("+") == 0)
            {
                if(isFindMax)
                {
                    if(isMax[sta][i-1]) y1 = maxVal[sta][i-1];
                    else { y1 = dp(sta, i-1, true); isMax[sta][i-1] = true; maxVal[sta][i-1] = y1; }
                    
                    if(isMax[i+1][en]) y2 = maxVal[i+1][en];
                    else { y2 = dp(i+1, en, true); isMax[i+1][en] = true; maxVal[i+1][en] = y2; }
                    
                    if(retVal < y1+y2) { retVal = y1 + y2; }
                }
                else
                {
                    if(isMin[sta][i-1]) y1 = minVal[sta][i-1];
                    else { y1 = dp(sta, i-1, false); isMin[sta][i-1] = true; minVal[sta][i-1] = y1; }
                    
                    if(isMin[i+1][en]) y2 = minVal[i+1][en];
                    else { y2 = dp(i+1, en, false); isMin[i+1][en] = true; minVal[i+1][en] = y2; }
                    
                    if(retVal > y1+y2) { retVal = y1 + y2; }
                }
            }
            else
            {
                if(isFindMax)
                {
                    if(isMax[sta][i-1]) y1 = maxVal[sta][i-1];
                    else { y1 = dp(sta, i-1, true); isMax[sta][i-1] = true; maxVal[sta][i-1] = y1; }
                    
                    if(isMin[i+1][en]) y2 = minVal[i+1][en];
                    else { y2 = dp(i+1, en, false); isMin[i+1][en] = true; minVal[i+1][en] = y2; }
                    
                    if(retVal < y1-y2) { retVal = y1 - y2; }
                }
                else
                {
                    if(isMin[sta][i-1]) y1 = minVal[sta][i-1];
                    else { y1 = dp(sta, i-1, false); isMin[sta][i-1] = true; minVal[sta][i-1] = y1; }
                    
                    if(isMax[i+1][en]) y2 = maxVal[i+1][en];
                    else { y2 = dp(i+1, en, false); isMax[i+1][en] = true; maxVal[i+1][en] = y2; }
                    
                    if(retVal > y1-y2) { retVal = y1 - y2; }
                } 
            }
        }
    }

    return retVal;
}

int solution(vector<string> arr)
{
    ys = arr;
    
    int answer = dp(0, ys.size() - 1, true);
    
    return answer;
}