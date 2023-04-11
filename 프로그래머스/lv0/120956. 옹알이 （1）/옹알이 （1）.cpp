#include <string>
#include <vector>

using namespace std;

int solution(vector<string> babbling) {
    int answer = 0;
    
    for(int i = 0; i < babbling.size(); i++)
    {
        string s = babbling[i];
        
        bool isSay = true;
        for(int a = 0; a < s.size(); )
        {
            if(s[a] == 'a')
            {
                if(a+2 >= s.size()) { isSay = false; break; }
                if(s[a+1] == 'y' && s[a+2] == 'a') a += 3;
                else { isSay = false; break; }
            }
            else if (s[a] == 'y')
            {
                if(a+1 >= s.size()) { isSay = false; break; }
                if(s[a+1] == 'e') a += 2;
                else { isSay = false; break; }
            }
            else if (s[a] == 'w')
            {
                if(a+2 >= s.size()) { isSay = false; break; }
                if(s[a+1] == 'o' && s[a+2] == 'o') a += 3;
                else { isSay = false; break; }
            }
            else if (s[a] == 'm')
            {
                if(a+1 >= s.size()) { isSay = false; break; }
                if(s[a+1] == 'a') a += 2;
                else { isSay = false; break; }
            }
            else { isSay = false; break; }
        }
        if(isSay) ++answer;
    }
    
    return answer;
}