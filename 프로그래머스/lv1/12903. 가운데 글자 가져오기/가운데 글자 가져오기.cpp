#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    
    if(s.size() % 2 == 1)
    {
        char a = s[s.size() / 2];
        answer += a;
    }
    else
    {
        char b = s[s.size() / 2 - 1];
        char c = s[s.size() / 2];
        answer += b; answer += c;
    }
    
    return answer;
}