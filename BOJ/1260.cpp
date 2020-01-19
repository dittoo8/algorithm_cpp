// #include <cstdio>
// #include <vector>
// #include <algorithm>
// #include <queue>
// using namespace std;
// int n,m,v;
// bool nums[1002];
// vector<int> vec[1002];
// void dfs(int x){
//     if (nums[x]) return;
//     nums[x] = true;
//     printf("%d ", x);
//     for(int i=0;i<vec[x].size();i++){
//         dfs(vec[x][i]);
//     }

// } 
// void bfs(int x) {
//     queue<int> q;
//     q.push(x);
//     nums[x] = true;
//     while(!q.empty()){
//         int f = q.front();
//         q.pop();
//         printf("%d ", f);
//         for(int i=0;i<vec[x].size();i++){
//             int y = vec[x][i];
//             if(!nums[y]){
//                 q.push(y);
//                 nums[y] = true;
//             }
            
//         }
//     }
// }
// int main(){
//     scanf("%d %d %d", &n, &m, &v);
//     for(int i=1;i<=m;i++){
//         int a, b;
//         scanf("%d %d", &a, &b);
//         vec[a].push_back(b);
//         vec[b].push_back(a);
//     }
//     dfs(v);
//     printf("\n");
//     bfs(v);

//     return 0;
// }
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int N, M, start;
int s, e;
vector<int> v[1001];
bool visit[1001];

void dfs(int start) {
	if (visit[start]) return;
	visit[start] = 1;
	cout << start << " ";

	for (int i = 0; i < v[start].size(); i++) {
		dfs(v[start][i]);
	}
}

void bfs(int start) {
	queue<int> q;

	q.push(start);
	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		if (visit[cur]) continue;
		visit[cur] = 1;
		cout << cur << " ";

		for (int i = 0; i < v[cur].size(); i++) {
			if (!visit[v[cur][i]]) q.push(v[cur][i]);
		}
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);

	cin >> N >> M >> start;
	for (int i = 0; i < M; i++) {
		cin >> s >> e;
		v[s].push_back(e);
		v[e].push_back(s);
	}

	for (int i = 1; i <= N; i++) sort(v[i].begin(), v[i].end());

	dfs(start);
	cout << '\n';
	memset(visit, 0, sizeof(visit));
	bfs(start);

	return 0;
}