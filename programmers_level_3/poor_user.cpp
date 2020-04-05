#include <iostream>
#include <string>
#include <cstring>
#include <vector>
using namespace std;
vector<int> v[10];
bool ck[1<<8];
int r;
int len;
void dfs(int idx,int bits){
    if (idx==len){
        ck[bits] =true;
        return;
    }
    for(int i=0;i<v[idx].size();i++){
        if(bits&1<<v[idx][i]) continue;
        dfs(idx+1,bits|1<<v[idx][i]);
    }
}
bool isPossible(string a,string b){
    if(a.size()!=b.size())return false;
    for(int i=0;i<a.size();i++){
        if(!(a[i]==b[i]||a[i]=='*'||b[i]=='*'))return false;
    }
    return true;
}
int solution(vector<string> user_id, vector<string> banned_id) {
    int answer=0;
    len = (int)banned_id.size();
    for(int i=0;i<banned_id.size();i++){
        for(int j=0;j<user_id.size();j++){
            if (user_id[j].length()<banned_id[i].length()) continue;
                if(isPossible(banned_id[i],user_id[j])){
                v[i].push_back(j);
            }
        }
    }
    dfs(0,0);
    for(int i=0;i<(1<<8);i++){
        if(ck[i]) answer++;
    }
    return answer;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<string> v;
    v.push_back("frodo");
    v.push_back("fradi");
    v.push_back("crodo");
    v.push_back("abc123");
    v.push_back("frodoc");
    vector<string> v2;
    v2.push_back("fr*d*");
    v2.push_back("abc1**");
    cout << solution(v,v2) <<endl;
    return 0;
}