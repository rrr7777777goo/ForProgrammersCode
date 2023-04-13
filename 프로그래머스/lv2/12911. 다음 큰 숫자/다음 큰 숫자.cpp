#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(int n) {
    
    string str = "";
    
    while(n > 0)
    {
        int mok = n / 2, namuzi = n % 2;
        
        char x = '0' + namuzi;
        string tmp = ""; tmp += x;
        str = tmp + str;
        
        n = mok;
    }
    
    int cntOne = 0;
    for(int i = str.size() - 1; i >= -1; i--)
    {
        if(i == -1)
        {
            string newOne = "1";
            str = newOne + str;
            break;
        }
        
        if(cntOne == 0)
        {
           if(str[i] == '1') { ++cntOne; str[i] = '0'; }
        }
        else
        {
            if(str[i] == '0') { str[i] = '1'; break; }
            else { ++cntOne; str[i] = '0'; }
        }
    }
    
    --cntOne;
    
    for(int i = str.size() - 1; i >= 0; i--)
    {
        if(cntOne == 0) break;
        
        str[i] = '1';
        --cntOne;
    }

    int answer = 0;
    
    int zari = 1;
    for(int i = str.size() - 1; i >= 0; i--)
    {
        if(str[i] == '1') answer += zari;
        zari *= 2;
    }
    
    return answer;
}