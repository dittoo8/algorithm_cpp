#include <iostream>
#include <string>
#include <vector>
#include <cstring>
using namespace std;
int nSize;
vector<int> v[5001];
bool ck[5001];
bool dfs(int s,int del,int cnt,int prev){
    ck[s]=true;
    for(int i=0;i<v[s].size();i++){
        if(v[s][i]==del || v[s][i]==prev) continue;
        if(ck[v[s][i]]) return false; 
        if(!dfs(v[s][i],del,cnt+1,s)) return false;
    }
    return true;
}
int solution(int n, vector<vector<int> > edges) {
    int answer = 0;
    nSize=n;
    for(int i=0;i<edges.size();i++){
        v[edges[i][0]].push_back(edges[i][1]);
        v[edges[i][1]].push_back(edges[i][0]);
    }
    for(int i=1;i<=n;i++){
        memset(ck,0,sizeof(ck));
        bool ckc = true;
        for(int j=1;j<=n;j++){
            if(i==j) continue;
            if(!ck[j]){
                if(!dfs(j,i,1,-1)) ckc = false;
            }
        }
        if(ckc) answer+=i;
    }
    return answer;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector<vector<int> > v;
    vector<int> v1;
    v1.push_back(1);
    v1.push_back(2);
    vector<int> v2;
    v2.push_back(1);
    v2.push_back(3);
    vector<int> v3;
    v3.push_back(2);
    v3.push_back(3);
    vector<int> v4;
    v4.push_back(2);
    v4.push_back(4);
    vector<int> v5;
    v5.push_back(3);
    v5.push_back(4);
    v.push_back(v1);
    v.push_back(v2);
    v.push_back(v3);
    v.push_back(v4);
    v.push_back(v5);
    cout << solution(4,v) <<endl;
    return 0;
}