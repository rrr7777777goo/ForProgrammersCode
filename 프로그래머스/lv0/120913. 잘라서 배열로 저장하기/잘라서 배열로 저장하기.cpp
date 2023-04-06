#include <string>
#include <vector>

using namespace std;

vector<string> solution(string my_str, int n) {
    vector<string> answer(1, "");
    
    int cnt = 0;
    for(int i = 0; i < my_str.size(); i++)
    {
        if(cnt == n) { cnt = 0; answer.push_back(""); }
        
        answer[answer.size()-1] += my_str[i]; ++cnt;
    }
    
    return answer;
}