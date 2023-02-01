#include <string>
#include <vector>
using namespace std;

vector<int> num;
int len, tar, ans;

void Add(int cnt, int sum)
{
    if(cnt == len)
    {
        if(sum == tar) ++ans;
    }
    else
    {
        Add(cnt + 1, sum + num[cnt]);
        Add(cnt + 1, sum + (-1 * num[cnt]));
    }
}

int solution(vector<int> numbers, int target) {
    num = numbers;
    len = numbers.size(); tar = target;
    
    Add(0, 0);
    
    return ans;
}