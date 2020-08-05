#include <iostream>
#include <vector>
#include <queue>
#define MAX 987654321
using namespace std;
int n,m,x;
int dist[1001][2];
void dijkstra(vector<pair<int, int > > adj[], int dir){
    priority_queue<pair<int, int> > pq;
    dist[x][dir]=0;
    pq.push({0,x});
    while(!pq.empty()){
        int now = pq.top().second;
        int cost = -pq.top().first;
        pq.pop();
        if (dist[now][dir] < cost) continue;
        for(int i=0;i<adj[now].size();i++){
            int next = adj[now][i].second;
            int nextCost = adj[now][i].first + cost;
            if (dist[next][dir]> nextCost){
                dist[next][dir] = nextCost;
                pq.push({-nextCost,next});
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    
    cin >> n >> m >> x;
    vector<pair<int, int> > adjA[n+1],adjB[n+1];
    while(m--){
        int a, b, c;
        cin >> a >> b >> c;
        adjA[a].push_back(make_pair(c,b));
        adjB[b].push_back(make_pair(c,a));
    }
    fill(&dist[0][0], &dist[n+1][0],MAX);
    dijkstra(adjA,0);
    dijkstra(adjB,1);
    int ans = 0;
    for(int i=1;i<=n;i++){
        int tmp = dist[i][0]+dist[i][1];
        if( tmp > ans) ans = tmp;
    }
    cout << ans << '\n';
    return 0;
}