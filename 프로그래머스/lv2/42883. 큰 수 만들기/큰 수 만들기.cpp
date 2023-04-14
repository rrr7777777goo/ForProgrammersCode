#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(string number, int k) {
    int cnt = 0;
    while(cnt < k)
    {
        for(int i = 0; i < number.size(); i++)
        {
            if(i == number.size()-1)
            {
                number.pop_back();
                break;
            }
            
            if(number[i] < number[i+1])
            {
                string newStr001 = number.substr(0, i);
                string newStr002 = number.substr(i+1, -1);
                number = newStr001;
                number += newStr002;
                break;
            }
        }
        ++cnt;
    }
    return number;
}