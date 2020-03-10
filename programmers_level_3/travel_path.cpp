#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
bool visit[10001];
vector<string> answer;
vector<string> temp;
bool dfs(string now,vector<vector<string> > tickets, int len){
    temp.push_back(now);
    if(len==tickets.size()){
        answer=temp;
        return true;
    }
    for(int i=0;i<tickets.size();i++){
        if(tickets[i][0]==now && !visit[i]){
            visit[i]= true;
            if(dfs(tickets[i][1],tickets,len+1)) return true;
            visit[i]= false;
        }
    }
    temp.pop_back();
    return false;
}
vector<string> solution(vector<vector<string> > tickets) {
    sort(tickets.begin(),tickets.end());
    if(dfs("ICN",tickets,0)) {
        return answer;
    }
    vector<string> v;
    return v;
}
int main(){
    vector<string> res;
    vector<vector<string> > v;
    vector<string> v1;
    v1.push_back("ICN");
    v1.push_back("JFK");
    vector<string> v2;
    v2.push_back("HND");
    v2.push_back("IAD");
    vector<string> v3;
    v3.push_back("JFK");
    v3.push_back("HND");
    v.push_back(v1);
    v.push_back(v2);
    v.push_back(v3);
    res = solution(v);
    for(int i=0;i<res.size();i++){
        cout << res[i] <<" ";
    }
    cout << endl;
    return 0;
}