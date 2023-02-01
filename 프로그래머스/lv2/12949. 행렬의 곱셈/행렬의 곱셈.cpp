#include <vector>
using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;
    
    for(int y = 0; y < arr1.size(); y++)
    {
        answer.push_back(vector<int>());
        for(int x = 0; x < arr2[0].size(); x++)
        {
            answer[y].push_back(0);
            for(int z = 0; z < arr1[y].size(); z++) answer[y][x] += arr1[y][z] * arr2[z][x];
        }
    }

    return answer;
}