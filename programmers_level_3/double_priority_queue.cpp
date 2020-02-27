#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
vector<int> solution(vector<string> operations) {
    vector<int> answer;
    answer.resize(2);
    string minDel = "D -1";
    string maxDel = "D 1";
    deque<int> dq;
    for(int i=0;i<operations.size();i++){
        if(operations[i]==minDel){
            if(!dq.empty()){
                dq.pop_front();
            }
        } else if (operations[i]==maxDel){
            if(!dq.empty()){
                dq.pop_back();
            }
        } else {
            string temp = operations[i].substr(2);
            int val = stoi(temp);
            dq.push_back(val);
            sort(dq.begin(),dq.end());
        }
    }
    answer[0] = dq.empty() ? 0 : dq.back();
    answer[1] = dq.empty()? 0 : dq.front();
    return answer;
}
int main(){
    vector<string> v;
    v.push_back("I 7");
    v.push_back("I 5");
    v.push_back("I -5");
    v.push_back("D -1");
    vector<int> res;
    res = solution(v);
    for(int i=0;i<2;i++){
        cout << res[i] << " ";
    }
    return 0;
}