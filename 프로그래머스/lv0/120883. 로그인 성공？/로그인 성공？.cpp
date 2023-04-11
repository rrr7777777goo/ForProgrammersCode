#include <string>
#include <vector>
#include <map>
using namespace std;

map<string, string> m_ID_PW;

string solution(vector<string> id_pw, vector<vector<string>> db) {
       
       for(int i = 0; i < db.size(); i++) m_ID_PW[db[i][0]] = db[i][1];
       
       
       if(m_ID_PW[id_pw[0]].compare("") == 0) return "fail";
       else if (m_ID_PW[id_pw[0]].compare(id_pw[1]) == 0) return "login";
       else return "wrong pw";
       
}