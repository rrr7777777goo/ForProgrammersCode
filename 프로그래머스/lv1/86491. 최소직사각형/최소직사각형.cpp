#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int width = 0, height = 0;
    
    for(int i = 0; i < sizes.size(); i++)
    {
        if(sizes[i][0] < sizes[i][1]) { int tmp = sizes[i][0]; sizes[i][0] = sizes[i][1]; sizes[i][1] = tmp; }
        
        if(sizes[i][0] > width) width = sizes[i][0];
        if(sizes[i][1] > height) height = sizes[i][1];
    }
    
    return width * height;
}