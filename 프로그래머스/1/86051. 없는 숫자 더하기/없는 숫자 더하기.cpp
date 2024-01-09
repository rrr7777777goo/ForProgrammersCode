#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers) {
    int answer = 0;
    
    vector<bool> isFind(10, false);
    
    for(int i = 0; i < numbers.size(); i++) {
        isFind[numbers[i]] = true;
    }
    
    for(int i = 1; i < 10; i++) {
        if(!isFind[i]) answer += i;
    }
    
    return answer;
}