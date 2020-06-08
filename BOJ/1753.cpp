#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int n, m;
const int INF = 1e9;
int dist[200001];
int main() {
    int start;
    scanf("%d %d", &n, &m);
    scanf("%d", &start);
    vector<pair<int, int > > a[n+1];
    for (int i=0; i<m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        a[u].push_back(make_pair(v,w));
    }
    fill(dist, dist+n+1, INF);
    // dijkstra
    priority_queue<pair<int, int> > pq;
    pq.push(make_pair(0,start));
    dist[start] = 0;
    while (!pq.empty()) {
        int now = pq.top().second;
        int cost = -pq.top().first;
        pq.pop();
        if (dist[now] < cost) continue;
        for(int i=0;i<a[now].size();i++){
            int next = a[now][i].first;
            int nextDist = a[now][i].second + cost;
            if (dist[next] > nextDist) {
                dist[next] = nextDist;
                pq.push(make_pair(-nextDist,next));
            }
        }
    }
    for(int i=1;i<=n;i++){
        dist[i] != INF ? printf("%d", dist[i]) : printf("INF");
		printf("\n");
    }
    return 0;
}