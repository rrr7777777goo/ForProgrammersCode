#include <string>
#include <vector>

using namespace std;

int solution(vector<int> ingredient) {
    int answer = 0;
    vector<int> tVec;
    for(int i = 0; i < ingredient.size(); i++)
    {
        tVec.push_back(ingredient[i]);
        if(ingredient[i] == 1)
        {
            if(tVec.size() >= 4)
            {
                int cI = tVec.size() - 1;
                if(tVec[cI] == 1 && tVec[cI-1] == 3 && tVec[cI-2] == 2 && tVec[cI-3] == 1)
                {
                    for(int a = 0; a < 4; a++) tVec.pop_back();
                    ++answer;
                }
            }
        }
    }
    return answer;
}