#include <iostream>
#include <vector>
#include <algorithm>
#define INF 1000000001
using namespace std;
vector<int> ar;
vector<pair<int, int>> tree;
int n, m, a, b;
pair<int, int> init(int s, int e, int node) {
	if (s == e) return tree[node] = { ar[s],ar[s] };
	auto p1 = init(s, (s + e) / 2, node * 2);
	auto p2 = init((s + e) / 2 + 1, e, node * 2 + 1);
	return tree[node] = { min(p1.first,p2.first),max(p1.second,p2.second) };
}
void query(int s, int e, int node, int l, int r, pair<int, int>& p) {
	if (l > e || r < s) return;
	if (l <= s && r >= e) {
		p.first = min(p.first, tree[node].first);
		p.second = max(p.second, tree[node].second);
		return;
	}
	query(s, (s + e) / 2, node * 2, l, r, p);
	query((s + e) / 2 + 1, e, node * 2 + 1, l, r, p);
}
int main() {
	ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
	cin >> n >> m;
	ar.resize(n);
	tree.resize(4 * n);
    for(int i=0;i<n;i++) {
        cin >> ar[i];
    }
	init(0, n - 1, 1);

	for (int i = 0; i < m; ++i) {
		pair<int, int> p(INF, 0);
		cin >> a >> b;
		query(0, n - 1, 1, a - 1, b - 1, p);
		cout << p.first << ' ' << p.second << '\n';
	}
	return 0;
}