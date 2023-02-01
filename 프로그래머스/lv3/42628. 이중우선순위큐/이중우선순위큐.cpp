#include <string>
#include <vector>
#include <map>
using namespace std;

map<int, int> mQu;

vector<int> solution(vector<string> operations) {
    for(int i = 0; i < operations.size(); i++)
    {
        char opt = operations[i][0];
        
        switch(opt)
        {
            case 'D':
                if(mQu.size() == 0) break;
                if(operations[i][2] == '1')
                {
                    if(mQu[mQu.rbegin()->first] == 1) mQu.erase(mQu.rbegin()->first);
                    else --mQu[mQu.rbegin()->first];
                }
                else
                {
                    if(mQu[mQu.begin()->first] == 1) mQu.erase(mQu.begin()->first);
                    else --mQu[mQu.begin()->first];
                }
                break;    
            case 'I':
                ++mQu[stoi(operations[i].substr(2, operations[i].size() - 2))];
                break;
        }
    }
    
    if(mQu.size() == 0) return vector<int>(2, 0);
    
    vector<int> answer = { mQu.rbegin()->first, mQu.begin()->first };
    return answer;
}