#include <string>
#include <vector>

using namespace std;

vector<int> solution(int money) {
    vector<int> ans(2, 0);
    ans[0] = money / 5500;
    ans[1] = money % 5500;
    return ans;
}