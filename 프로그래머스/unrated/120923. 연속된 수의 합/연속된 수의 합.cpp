#include <string>
#include <vector>

using namespace std;

vector<int> solution(int num, int total) {
    vector<int> answer;
    
    int x = 0;
    
    for(int i = 1; i < num; i++) {
        x += i;
    }
    
    int a = (total - x) / num;
    
    for(int i = 0; i < num; i++) {
        answer.push_back(a+i);
    }
    
    return answer;
}