#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> arr) {
    sort(arr.begin(), arr.end());
    
    int answer = arr[arr.size() - 1];
    
    while(true)
    {
        bool isWrong = false;
        
        for(int i = 0; i < arr.size(); i++)
        {
            if(answer % arr[i] > 0) { isWrong = true; break; }
        }
        
        if(!isWrong) break;
        else ++answer;
    }

    return answer;
}