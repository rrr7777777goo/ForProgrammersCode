#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(string number, int k) {
    int cnt = 0;
    
    for(int i = 0; i < number.size()-1; )
    {
        if(cnt == k) break;
        
        if(number[i] < number[i+1])
        {
            string newStr001 = number.substr(0, i), newStr002 = number.substr(i+1, -1);
            number = newStr001; number += newStr002;
            ++cnt;
            i = i-1 >= 0 ? i-1 : 0;
        }
        else i++;
    }
    
    while(cnt < k) { number.pop_back(); ++cnt; }
    
    return number;
}