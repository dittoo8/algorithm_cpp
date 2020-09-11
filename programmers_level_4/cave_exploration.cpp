#include <iostream>
#include <string>
#include <vector>
#include <queue>
#define MAX 200001
using namespace std;
bool flag = true;
vector<int> adj[MAX];
vector<int> direct_adj[MAX];
int idx[MAX];
bool finished[MAX];
int cnt = 1;
void dfs(int x){
    if(flag == false) return;
    idx[x] = cnt++;
    for(int i=0;i<direct_adj[x].size();i++){
        int next = direct_adj[x][i];
        if(idx[next]==0){
            dfs(next);
        }else if(idx[x]<idx[next]) continue;
        else if (finished[next]==false){
            flag = false;
            return;
        }
    }
    finished[x] = true;
    return;
}
bool solution(int n, vector<vector<int>> path, vector<vector<int>> order) {
    bool answer = true;
    for(int i=0;i<path.size();i++){
        adj[path[i][0]].push_back(path[i][1]);
        adj[path[i][1]].push_back(path[i][0]);
    }
    vector<bool> visited(n+1,false);
    queue<int> q;
    q.push(0);
    visited[0]= true;
    while(!q.empty()){
        int x = q.front(); q.pop();
        for(int i=0;i<adj[x].size();i++){
            int next = adj[x][i];
            if (visited[next]) continue;
            visited[next] = true;
            q.push(next);
            direct_adj[x].push_back(next);
        }
    }
    for(int i=0;i<order.size();i++){
        direct_adj[order[i][0]].push_back(order[i][1]);
    }
    dfs(0);
    return flag;
}
int main(){
    vector<vector<int> > v = {{0,1},{0,3},{0,7},{8,1},{3,6},{1,2},{4,7},{7,5}};
    vector<vector<int> > v2 = {{8,5},{6,7},{4,1}};

    bool ans = solution(9,v,v2);

    if (ans) cout << "true" << endl;
    else cout << "false" << endl;
    return 0;
}