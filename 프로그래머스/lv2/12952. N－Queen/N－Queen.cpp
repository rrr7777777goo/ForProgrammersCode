#include <string>
#include <vector>
using namespace std;

int nN, ans;

bool isBatch[13][13]; bool isAlreadyUsed[13];
void Find_Route(int cnt)
{
    for(int i = 1; i <= nN; i++)
    {
        if(isAlreadyUsed[i]) continue;
        bool isWrong = false; int le = i-1, ri = i+1;
        for(int z = (cnt-1); z >= 1; z--)
        {
            if(le >= 1) { if(isBatch[z][le]) {isWrong = true; break;} --le; }
            if(ri <= nN){ if(isBatch[z][ri]) {isWrong = true; break;} ++ri; }
        }
        if(!isWrong)
        {
            isAlreadyUsed[i] = true; isBatch[cnt][i] = true;
            if(cnt == nN) ++ans; else Find_Route(cnt+1);
            isBatch[cnt][i] = false; isAlreadyUsed[i] = false;
        }  
    }
}

int solution(int n) {
    nN = n;
    Find_Route(1);
    return ans;
}