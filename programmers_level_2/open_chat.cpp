#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <map>
using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    vector<string> uid;
    map<string ,string> nick;
    stringstream ss; string action; string name; string nickname;
    for(int i=0;i<record.size();i++){
        ss.str(record[i]);
        ss >> action;
        if(action == "Enter"){
            ss >> name;
            ss >> nickname;
            answer.push_back("님이 들어왔습니다.");
            uid.push_back(name);
            nick[name] = nickname;
        } else if (action == "Leave"){
            ss >> name;
            answer.push_back("님이 나갔습니다.");
            uid.push_back(name);
        } else {
            ss >> name;
            ss >> nickname;
            nick[name] = nickname;
        }
        ss.clear();
    }
    for(int i=0;i<answer.size();i++){
        answer[i] = nick[uid[i]]+answer[i];
    }
    return answer;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector<string> v;
    v.push_back("Enter uid1234 Muzi");
    v.push_back("Enter uid4567 Prodo");
    v.push_back("Leave uid1234");
    v.push_back("Enter uid1234 Prodo");
    v.push_back("Change uid4567 Ryan");
    vector<string> res;
    res = solution(v);
    for(int i=0;i<res.size();i++){
        cout << res[i] << endl;
    }
    return 0;
}