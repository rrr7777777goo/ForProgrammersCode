#include <string>
#include <vector>

using namespace std;

string solution(string my_string, int n) {
    string ans = "";
    
    for(int i = 0; i < my_string.size(); i++)
    {
        char c = my_string[i];
        for(int x = 0; x < n; x++) ans += c;
    }
    
    return ans;
}