#include <iostream>
#include <queue>
#include <vector>
#define MAX 501
#define INF 987654321
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m,dist[MAX],cnt = 0;
    vector<int> adj[MAX];
    priority_queue<pair<int, int> > pq;
    cin >> n >> m;
    int u, v;
    for(int i=0;i<m;i++){
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    fill(&dist[0], &dist[n]+1,INF);
    dist[1] = 0;
    pq.push(make_pair(1,0));
    while(!pq.empty()){
        int x = pq.top().first;
        int nowDist = -pq.top().second;
        pq.pop();
        for(int t= 0; t < adj[x].size();t++){
            int next = adj[x][t];
            if(dist[next] >= nowDist + 1){
                dist[next] = nowDist+1;
                pq.push(make_pair(next,-(nowDist+1)));
            }
        }
    }
    for(int i=2;i<=n;i++){
        if (dist[i] <= 2) cnt++;
    }
    cout << cnt << '\n';
    return 0;
}