#include <string>
#include <vector>
using namespace std;

int solution(int n) {
    int answer = 0;
    
    int cnt = 0;
    while (cnt < n)
    {
        ++answer;
        
        bool isCurseNumber = false;
        
        if(answer % 3 == 0) isCurseNumber = true;
        else
        {
            string str = to_string(answer);
            
            for(int x = 0; x < str.size(); x++)
            {
                if(str[x] == '3') { isCurseNumber = true; break; }
            }
        }
        
        if(!isCurseNumber) ++cnt;
    }
    
    return answer;
}