#include <string>
#include <vector>
#include <queue>
using namespace std;

struct Num
{
    string num;
    Num(string n) { num = n; }
    
    bool operator<(const Num &n) const
    {
        int len = num.size() > n.num.size() ? num.size() : n.num.size();
        
        int i1 = 0, i2 = 0;
        
        for(int i = 0; i < len; i++)
        {
            if(num[i1] != n.num[i2]) return num[i1] < n.num[i2];
            i1 = (i1 + 1) % num.size(); i2 = (i2 + 1) % n.num.size();
        }
        
        return num[num.size() - 1] < n.num[n.num.size() - 1];
    }
};

string solution(vector<int> numbers) {
    string answer = "";
    
    priority_queue<Num> qu;
    
    for(int i = 0; i < numbers.size(); i++)
    {
        string a = to_string(numbers[i]);
        qu.push(Num(a));
    }
    
    while(!qu.empty())
    {
        string x = qu.top().num; qu.pop();
        answer += x;
    }
    
    if(answer[0] == '0') { answer = "0"; }
    
    return answer;
}