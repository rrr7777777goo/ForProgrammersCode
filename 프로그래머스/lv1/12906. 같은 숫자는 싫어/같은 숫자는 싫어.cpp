#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> ans;
    
    ans.push_back(arr[0]);
    
    for(int x = 0; x < arr.size(); x++) if(ans[ans.size() - 1] != arr[x]) ans.push_back(arr[x]);
    
    return ans;
}