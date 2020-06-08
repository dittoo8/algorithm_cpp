#include <cstdio>
#include <queue>
#include <vector>
using namespace std;
const int INF = 1e9;
vector<pair<int, int > > adj[1001];
int d[1001];
void dijkstra(int start, int end) {
    d[start]=0;
    priority_queue<pair<int ,int> > pq;
    //pq.first = -cost, second = node
    pq.push(make_pair(0,start));
    while(!pq.empty()){
        int now = pq.top().second;
        int cost =  -pq.top().first;
        pq.pop();
        if (d[now] < cost ) continue;
        for(int i=0;i<adj[now].size();i++){
            int next = adj[now][i].first;
            int nextDist = cost + adj[now][i].second;
            if (nextDist < d[next] ){
                d[next]= nextDist;
                pq.push(make_pair(-nextDist, next));
            }
        }
    }
}
int main(){
    int n,m,s,e;
    scanf("%d", &n);
    scanf("%d", &m);
    for(int i=0;i<m;i++){
        int u,v,c;
        scanf("%d %d %d", &u, &v, &c);
        adj[u].push_back(make_pair(v,c));
    }
    fill(d,d+n+1,INF);
    scanf("%d %d", &s, &e);
    dijkstra(s,e);
    printf("%d\n", d[e]);
    return 0;
}