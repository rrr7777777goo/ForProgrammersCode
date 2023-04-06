#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> numbers) {
    priority_queue<int> qu_max;
    priority_queue<int, vector<int>, greater<int>> qu_min;
    
    for(int i = 0; i < numbers.size(); i++) { qu_max.push(numbers[i]); qu_min.push(numbers[i]); }
    
    int c1 = qu_max.top(), c2 = qu_min.top();
    qu_max.pop(); c1 *= qu_max.top(); qu_min.pop(); c2 *= qu_min.top();
    
    return c1 > c2 ? c1 : c2;  
}