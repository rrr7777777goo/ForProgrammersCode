#include <string>
#include <vector>
#include <map>
using namespace std;

map<char, int> ma;
typedef map<char, int>::iterator iter;

string solution(string my_string) {
    string answer = "";
    for(int i = 0; i < my_string.size(); i++) { if(my_string[i] <= 'Z') my_string[i] += 32; ++ma[my_string[i]]; }
    
    for(iter it = ma.begin(); it != ma.end(); it++)
    {
        while(it->second > 0)
        {
            answer += it->first;
            --(it->second);
        }
    }
    
    return answer;
}