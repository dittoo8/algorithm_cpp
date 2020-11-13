#include <iostream>
#include <vector>
#define MAX 10001
using namespace std;
int n,m,tmax,cnt;
vector<int> adj[MAX], ans;
bool visit[MAX];
void dfs(int x){
    visit[x] = true;
    cnt++;
    for(int i=0;i<adj[x].size();i++){
        if(visit[adj[x][i]]==false){
            dfs(adj[x][i]);
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    int u,v;
    for(int i=0;i<m;i++){
        cin >> u >> v;
        adj[v].push_back(u);
    }
    for(int i=1;i<=n;i++){
        cnt = 0;
        fill(&visit[0], &visit[n]+1,0);
        dfs(i);
        if(cnt > tmax){
            ans.clear();
            ans.push_back(i);
            tmax = cnt;
        }else if (cnt == tmax){
            ans.push_back(i);
        }
    }
    for(int i=0;i<ans.size();i++){
        cout << ans[i] << ' ';
    }
    return 0;
}