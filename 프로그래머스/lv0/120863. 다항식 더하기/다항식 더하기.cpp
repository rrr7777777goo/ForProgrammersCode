#include <string>
#include <vector>
using namespace std;

string solution(string polynomial) {
    
    int valueO = 0, valueX = 0;
    string str = ""; bool isX = false;
    
    for(int i = 0; i <= polynomial.size(); i++)
    {
        if(i == polynomial.size())
        {
            if(str.compare("") == 0) { if(isX) str = "1"; else break; }
            if(isX) valueX += stoi(str); else valueO += stoi(str);
            break;
        }
        
        if(polynomial[i] == 'x') isX = true;
        else if (polynomial[i] >= '0' && polynomial[i] <= '9')
        {
            str += polynomial[i];
        }
        else if (polynomial[i] == '+')
        {
            if(isX && str.compare("") == 0) str = "1";
            if(isX) { valueX += stoi(str); isX = false; } else valueO += stoi(str);
            
            str = "";
        }
    }
    
    string answer = "";
    
    if(valueX > 0)
    {
        if(valueX > 1) answer += to_string(valueX); answer += "x";
        if(valueO > 0) answer += " + ";
    }
    if(valueO > 0)
    {
        answer += to_string(valueO);
    }
    
    if(answer.compare("") == 0) answer = "0";
    
    return answer;
}