#include <vector>
using namespace std;

int kK; vector<vector<int>> dDD;
int len;
int answer;
int checkCount;
bool isAlreadyCheck[8];

void Check_Value(int c)
{
    for(int i = 0; i < dDD.size(); i++)
    {
        if(isAlreadyCheck[i]) continue;
        
        if(kK >= dDD[i][0])
        {
        isAlreadyCheck[i] = true;
        kK -= dDD[i][1];
        ++checkCount;
        if(c == len)
        {
            if(checkCount > answer) answer = checkCount;
        }
        else
        {
            Check_Value(c+1);
        }
        --checkCount;
        kK += dDD[i][1];
        isAlreadyCheck[i] = false;            
        }
    }
    
    if(checkCount > answer) answer = checkCount;
}

int solution(int k, vector<vector<int>> dungeons) {
    kK = k;
    dDD = dungeons;
    len = dungeons.size();
    
    Check_Value(1);
    
    return answer;
}