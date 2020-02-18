#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;
bool visit[201];
vector<int> v[101];
int answer;
// void bfs(int n){
//     queue<int> q;
//     visit[n] = true;
//     q.push(n);
//     while(!q.empty()){
//         int now = q.front();
//         q.pop();
//         for(int j=0;j<v[now].size();j++){
//             if (!visit[v[now][j]]){
//                 visit[v[now][j]] = true;
//                 q.push(v[now][j]);
//             }
//         }
//     }
//     answer++;
// }
void dfs(int n){
    visit[n] = true;
    for(int i=0;i<v[n].size();i++){
        if (!visit[v[n][i]]){
            visit[v[n][i]] = true;
            dfs(v[n][i]);
        }
    }
}
int solution(int n, vector<vector<int> > computers) {
    for(int i=0;i<computers.size();i++){
        for(int j=0;j<computers[i].size();j++){
            if(i==j) continue;
            if(computers[i][j]==1){
                v[i+1].push_back(j+1);
            }
        }
    }
    for(int i=1;i<=n;i++){
        if (!visit[i]){
            // bfs(i);
            dfs(i);
            answer++;
        }
    }
    return answer;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector<vector<int> > v;
    vector<int> v1;
    v1.push_back(1);
    v1.push_back(1);
    v1.push_back(0);
    vector<int> v2;
    v2.push_back(1);
    v2.push_back(1);
    v2.push_back(0);
    vector<int> v3;
    v3.push_back(0);
    v3.push_back(0);
    v3.push_back(1);
    v.push_back(v1);
    v.push_back(v2);
    v.push_back(v3);
    cout << solution(3, v) << endl;

    return 0;
}