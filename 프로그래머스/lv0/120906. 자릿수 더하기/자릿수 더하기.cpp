#include <string>
#include <vector>
using namespace std;

int solution(int n) {
    string sn = to_string(n);
    
    int answer = 0;
    for(int i = 0; i < sn.size(); i++)
    {
        answer += (sn[i] - '0');
    }
    return answer;
}