#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

struct File
{
    int vec_idx;
    
    string head; int number;
    
    File(int v, string h, int n) { vec_idx = v; head = h; number = n; }
    
    bool operator>(const File &f) const
    {
        if(head.compare(f.head) != 0)
        { 
            if(head.compare(f.head) > 0) return true;
            else return false;
        }
        else if (number != f.number) { return number > f.number; }
        else { return vec_idx > f.vec_idx; }
    }
};

vector<string> solution(vector<string> files) {
    vector<string> answer;
    
    priority_queue<File, vector<File>, greater<File>> qu;
    for(int a = 0; a < files.size(); a++)
    {
        bool isNumFind = false; string head, number;
        for(int i = 0; i < files[a].size(); i++)
        {
            if(files[a][i] >= '0' && files[a][i] <= '9')
            {
                isNumFind = true;
                number += files[a][i];
            }
            else
            {
                if(isNumFind) break;
                else 
                {
                    char c = files[a][i]; if(c >= 'a' && c <= 'z') c -= 32;
                    head += c;
                }
            }
        }
        
        qu.push(File(a, head, stoi(number)));
    }
    
    while(!qu.empty()) { answer.push_back(files[qu.top().vec_idx]); qu.pop(); }
    
    return answer;
}