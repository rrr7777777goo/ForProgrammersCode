#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> dots) {
    int answer = 0;
    
    int lX = 256, rX = -256, uY = -256, dY = 256;
    
    for(int i = 0; i < dots.size(); i++)
    {
        int cX = dots[i][0], cY = dots[i][1];
        if(cX < lX) lX = cX; if(cX > rX) rX = cX;
        if(cY > uY) uY = cY; if(cY < dY) dY = cY;
    }
    return (rX - lX) * (uY - dY);
}