#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> people, int limit) {
    sort(people.begin(), people.end());
    
    int answer = 0;
    
    int f = 0, b = people.size() - 1;
    
    while(f < b)
    {
        int big = people[b];
        int small = people[f];
        
        ++answer; --b;
        if((big + small) <= limit) ++f;
    }
    
    if(f == b) ++answer;
    
    return answer;
}