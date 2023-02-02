#include <string>
#include <vector>

using namespace std;

int solution(int order) {
    int answer = 0;
    
    string s = to_string(order);
    
    for(int i = 0; i < s.size(); i++)
    {
        if((s[i] - '0') % 3 == 0 && (s[i] - '0') > 0) ++answer;
    }
    return answer;
}