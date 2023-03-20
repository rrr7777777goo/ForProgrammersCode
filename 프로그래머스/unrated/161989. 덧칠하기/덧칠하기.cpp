#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<bool> isPaint;
int solution(int n, int m, vector<int> section) {
    isPaint = vector<bool>(n+1, true);
    
    for(int i = 0; i < section.size(); i++) isPaint[section[i]] = false;

    int answer = 0;
    
    for(int x = 1; x <= (n - m + 1); x++)
    {
        if(!isPaint[x])
        {
            ++answer;
            for(int y = x; y <= (x + m - 1); y++) isPaint[y] = true;
        }
    }
    
    for(int x = (n - m + 2); x <= n; x++)
    {
        
        if(!isPaint[x]) { cout << x << "가 아직 안칠해짐!" << endl; ++answer; break; }
    }
    
    
    return answer;
}