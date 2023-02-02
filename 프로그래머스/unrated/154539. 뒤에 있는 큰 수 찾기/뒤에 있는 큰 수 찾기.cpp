#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> ans; ans.push_back(-1);
    
    vector<int> big; big.push_back(numbers[numbers.size() - 1]);
    
    for(int i = numbers.size() - 2; i >= 0; i--)
    {
        int x = numbers[i];
        
        if(x > big[0])
        {
            ans.push_back(-1);
            big = vector<int>(1, x);
            continue;
        }
        
        while(true)
        {
            if(x < big[big.size() - 1])
            {
                ans.push_back(big[big.size() - 1]);
                big.push_back(x);
                break;
            }
            else big.pop_back();
            
            if(big.size() == 0)
            {
                ans.push_back(-1);
                big = vector<int>(1, x);
                break;
            }
        }
    }
    
    reverse(ans.begin(), ans.end());
    return ans;
}