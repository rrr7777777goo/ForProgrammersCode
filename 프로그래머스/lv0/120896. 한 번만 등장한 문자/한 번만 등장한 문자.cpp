#include <string>
#include <vector>
#include <map>
using namespace std;

map<char, int> ma;
typedef map<char, int>::iterator iter;
string solution(string s) {
    string answer = "";
    
    for(int i = 0; i < s.size(); i++)
    {
        ++ma[s[i]];
    }
    
    for(iter it = ma.begin(); it != ma.end(); it++)
    {
        if(it->second == 1) answer += it->first;
    }
    
    return answer;
}