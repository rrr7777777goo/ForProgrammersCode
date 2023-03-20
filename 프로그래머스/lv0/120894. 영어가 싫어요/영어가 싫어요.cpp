#include <string>
#include <vector>

using namespace std;

long long solution(string numbers) {
    string answer = "";
    
    for(int i = 0; i < numbers.size(); )
    {
        if(numbers[i] == 'e') { answer += '8'; i += 5; }
        else if (numbers[i] == 'f')
        {
            if(numbers[i+1] == 'i') answer += '5';
            else answer += '4';
            i += 4;
        }
        else if (numbers[i] == 'n') { answer += '9'; i += 4; }
        else if (numbers[i] == 'o') { answer += '1'; i += 3; }
        else if (numbers[i] == 's')
        {
            if(numbers[i+1] == 'e') { answer += '7'; i += 5; }
            else { answer += '6'; i += 3; }
        }
        else if (numbers[i] == 't')
        {
            if(numbers[i+1] == 'h') { answer += '3'; i += 5; }
            else { answer += '2'; i += 3; }
        }
        else { answer += '0'; i += 4; }
    }
    
    return stoll(answer);
}