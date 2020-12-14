#include <iostream>
#include <vector>
#define INF 987654321
#define MAX 502
using namespace std;
struct edge {
    int u,v,c;
};
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n,m;
    cin >> n >> m;
    long long dist[MAX];
    fill(&dist[0], &dist[n]+1,INF);
    dist[1]= 0;
    vector<edge> edges;
    edges.resize(m);
    int u,v,c;
    for(int i=0;i<m;i++){
        cin >> u >> v >> c;
        edges[i].u = u, edges[i].v = v, edges[i].c = c;
    }
    for(int i=0;i<n-1;i++){
        for(int j=0;j<m;j++){
            if(dist[edges[j].u] == INF) continue;
            if(dist[edges[j].v] > dist[edges[j].u] + edges[j].c) dist[edges[j].v] = dist[edges[j].u] + edges[j].c;
        }
    }
    for(int i=0;i<m;i++){
        if(dist[edges[i].u] == INF) continue;
        if(dist[edges[i].v] > dist[edges[i].u] + edges[i].c){
            cout << -1 << '\n';
            return 0;
        }
    }
    for(int i=2;i<=n;i++){
        if(dist[i]==INF) cout<< -1 << '\n';
        else cout << dist[i] << '\n';
    }
    return 0;
}