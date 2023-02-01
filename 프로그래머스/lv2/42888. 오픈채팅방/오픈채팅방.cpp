#include <string>
#include <vector>
#include <sstream>
#include <map>
using namespace std;

map<string, string> nickname;
vector<string> list_id, list_type;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    
    for(int i = 0; i < record.size(); i++)
    {
        string tmp_str = record[i];
        stringstream ss(tmp_str);
        
        vector<string> words;
        string w; while(getline(ss, w, ' '))  words.push_back(w);
        
        string _id = words[1];
        if(words[0].compare("Enter") == 0)
        {
            nickname[words[1]] = words[2];
            list_id.push_back(words[1]);
            list_type.push_back("Enter");
        }
        else if (words[0].compare("Leave") == 0)
        {
            list_id.push_back(words[1]);
            list_type.push_back("Leave");
        }
        else if (words[0].compare("Change") == 0)
        {
            nickname[_id] = words[2];
            list_id.push_back(words[1]);
            list_type.push_back("Change");
        }
    }
    
    for(int i = 0; i < list_id.size(); i++)
    {
        string tmp;
        if(list_type[i].compare("Enter") == 0)
        {
            tmp += nickname[list_id[i]];
            tmp += "님이 들어왔습니다.";
            answer.push_back(tmp);
        }
        else if(list_type[i].compare("Leave") == 0)
        {
            tmp += nickname[list_id[i]];
            tmp += "님이 나갔습니다.";
            answer.push_back(tmp);
        }
    }
    
    return answer;
}