#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(string s) {
    int answer = s.size();
    
    int maxi = s.size() / 2;
    
    for(int c = 1; c <= maxi; c++)
    {
        int sum = 0;
        string prev = ""; int cnt = 0;
        
        int fi = (s.size() / c) * c;
        for(int i = 0; i < fi; i += c)
        {
            string curr = ""; 
            for(int a = i; a < (i+c); a++) curr += s[a];
            
            if(prev.compare("") == 0) { prev = curr; cnt = 1; }
            else
            {
                if(prev.compare(curr) != 0)
                {
                    if(cnt >= 2)
                    {
                        string cntStr = to_string(cnt);
                        int len = cntStr.size();
                        sum += (len+c);
                    }
                    else sum += c;
                    cnt = 1;
                    prev = curr;
                }
                else ++cnt;
            }
            
            if(i+c >= fi)
            {
                sum += s.size() - fi;
                if(cnt >= 2)
                {
                    string cntStr = to_string(cnt);
                    int len = cntStr.size();
                    sum += (len+c);
                }
                else sum += c;
                break;
            }
        }
        if(sum < answer) answer = sum;
    }
    
    return answer;
}
