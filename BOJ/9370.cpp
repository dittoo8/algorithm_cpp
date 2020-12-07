#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define INF 987654321
#define MAX 2001
using namespace std;
vector<pair<int,int>> adj[MAX];
vector<int> dijkstra(int start,int n) {
	vector<int> dp(n + 1, INF);
	dp[start] = 0;
    priority_queue<pair<int, int> > pq;
	pq.push(make_pair(0,start ));
	while (!pq.empty()) {
		int now = pq.top().second;
		int dis = -pq.top().first;
		pq.pop();
		if (dis > dp[now]) continue;
		for (int i = 0; i < adj[now].size(); i++) {
			int next = adj[now][i].first;
			int nDis = adj[now][i].second;
			if (dp[next] > nDis + dis) {
				dp[next] = nDis + dis;
				pq.push(make_pair(-dp[next], next));
			}
		}
	}
	return dp;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		int n, m, t, s, g, h,distMid=0;
		cin >> n >> m >> t >> s >> g >> h;
		for (int i = 0; i <= n; i++) adj[i].clear();
		for (int i = 0; i < m; i++) {
			int a, b, d;
			cin >> a >> b >> d;
			adj[a].push_back({ b,d });
			adj[b].push_back({ a,d });
			if ((a == g && b == h) || (a == h && b == g)) distMid = d;
		}
		vector<int> dist(t);
		for (int i = 0; i < t; i++) {
			cin >> dist[i];
		}
		sort(dist.begin(), dist.end());
		vector<int> dp = dijkstra(s, n);
		int mid1 = 0, mid2 = 0;
		if (dp[g] > dp[h]) {
			mid1 = h, mid2 = g;
		}else {
			mid1 = g, mid2 = h;
		}
		vector<int> dp2 = dijkstra(mid2, n);
		for (int i = 0; i < t; i++) {
			if (dp[dist[i]] == dp[mid1] + dp2[dist[i]] + distMid) {
				cout << dist[i] << ' ';
			}
		}
		cout << '\n';
	}
	return 0;
}