#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(string word) {
    
    while(word.size() < 5) word += 'Z';
    
    int int_W[6];
    for(int i = 1; i <= 5; i++)
    {
        switch(word[i-1])
        {
            case 'Z': int_W[i] = 0; break; case 'A': int_W[i] = 1; break;
            case 'E': int_W[i] = 2; break; case 'I': int_W[i] = 3; break;
            case 'O': int_W[i] = 4; break; case 'U': int_W[i] = 5; break;
        }
    }

    int answer = 0;
    int forCheck[6]; for(int i = 1; i <= 5; i++) forCheck[i] = 0;
    while(true)
    {
        ++answer;
        
        if(forCheck[1] == 0) ++forCheck[1];
        else if(forCheck[2] == 0) ++forCheck[2]; else if(forCheck[3] == 0) ++forCheck[3];
        else if(forCheck[4] == 0) ++forCheck[4]; else  ++forCheck[5];

        for(int i = 5; i >= 1; i--)
        {
            if(forCheck[i] == 6)
            {
                forCheck[i] = 0;
                if(i >= 2) ++forCheck[i-1];
            }
        }
        
        bool isAnswer = true;
        for(int i = 1; i <= 5; i++) if(forCheck[i] != int_W[i]) {isAnswer = false; break; }
        if(isAnswer) break;
    }
    
    return answer;
}