#include <string>
#include <vector>

using namespace std;

int solution(vector<int> sides) {
    
    if(sides[1] < sides[0]) { int tmp = sides[1]; sides[1] = sides[0]; sides[0] = tmp; }
    
    int answer = 0;
    
    for(int i = 1; i <= sides[1]; i++) { if(sides[0] + i > sides[1]) ++answer; }
    
    int x = sides[1] + 1;
    
    while(x < sides[0] + sides[1]) { ++answer; ++x; }
    
    return answer;
}