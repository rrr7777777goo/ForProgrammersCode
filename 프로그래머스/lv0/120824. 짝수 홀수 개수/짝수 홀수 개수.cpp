#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> num_list) {
    vector<int> ans(2, 0);
    
    for(int i = 0; i < num_list.size(); i++)
    {
        if(num_list[i]%2 == 0) ++ans[0];
        else ++ans[1];
    }
    return ans;
}