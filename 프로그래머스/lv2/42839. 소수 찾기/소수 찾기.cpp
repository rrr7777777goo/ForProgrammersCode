#include <string>
#include <vector>
using namespace std;

int isNotSoSu[10000000]; bool isAlreadyFindSoSu[10000000];

string nb; int len; int answer;

bool isAlreadyUsed[7]; string checkstr = "";

void Find_SoSu(int c)
{
    if(c == 1)
    {
        isNotSoSu[0] = true; isNotSoSu[1] = true;
        for(int i = 2; i <= 9999999; i++)
        {
            if(isNotSoSu[i] == true) continue;
            for(int u = i * 2; u <= 9999999; u += i) isNotSoSu[u] = true;
        }
    }
    
    for(int i = 0; i < nb.size(); i++)
    {
        if((c == 0 && nb[i] == '0') || isAlreadyUsed[i]) continue;
        
        isAlreadyUsed[i] = true;
        string backupstr = checkstr; checkstr += nb[i];
        
        if(c == len)
        {
            int tmp = stoi(checkstr);
            if(!isNotSoSu[tmp] && !isAlreadyFindSoSu[tmp])
            {
                ++answer;
                isAlreadyFindSoSu[tmp] = true;
            }
        }
        else Find_SoSu(c+1);
        
        checkstr = backupstr;
        isAlreadyUsed[i] = false;
    }
    
    if(c >= 2)
    {             
        int tmp = stoi(checkstr);
        if(!isNotSoSu[tmp] && !isAlreadyFindSoSu[tmp])
        {
            ++answer;
            isAlreadyFindSoSu[tmp] = true;
        }
    }
}

int solution(string numbers) {
   nb = numbers;
   len = numbers.size();
   Find_SoSu(1);

    return answer;
}