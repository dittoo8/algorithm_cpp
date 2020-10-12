#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 100002
using namespace std;
int n, a, b, c;
vector<pair <long long, long long> > v[MAX];
bool chk[MAX];
int ans,ed;
void DFS(int n, int s) {    
    chk[n] = true;  
    if (s > ans) {
        ans = s;
        ed = n;
    }
    for (int i = 0; i < v[n].size(); i++) {
        if (chk[v[n][i].first] == false) {
            DFS(v[n][i].first, s + v[n][i].second);
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a;
        while (true) {
            cin >> b;
            if (b == -1) break;
            cin >> c;
            v[a].push_back(make_pair(b, c));
        }
    }
    DFS(1, 0);
    ans = 0;
    fill(&chk[0],&chk[n]+1, 0);
    DFS(ed, 0);
    cout << ans << '\n';
    return 0;
}
