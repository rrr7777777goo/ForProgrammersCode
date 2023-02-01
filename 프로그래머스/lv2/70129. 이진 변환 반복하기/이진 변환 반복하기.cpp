#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
    vector<int> ans(2, 0);
    
    string s2 = s;
    while(s2.size() > 1)
    {
        ++ans[0];
        
        string s3 = "";
        for(int i = 0; i < s2.size(); i++) 
        {
            if(s2[i] == '1') s3 += s2[i];
            else ++ans[1];
        }
        
        string s4 = ""; int i_s4 = s3.size();
        while(i_s4 > 0)
        {
            int na = i_s4 % 2;
            string s5 = "";
            s5 += (char)(na + '0');
            s4 = s5 + s4;
            i_s4 /= 2;
        }
        s2 = s4;
    }
    
    return ans;
}