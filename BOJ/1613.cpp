#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, k;
    cin >> n >> k;
    bool road[401][401] = {};
    while (k--) {
        int s, e;
        cin >> s >> e;
        road[s][e] = true;
    }

    for (int t = 1; t <= n; t++) {
        for (int i = 1; i <= n; i++) {
            if (!road[i][t]) continue;
            for (int j = 1; j <= n; j++) {
                if(road[i][t] & road[t][j] ){
                    road[i][j] = true;
                }
            }
        }
    }
    int m;
    cin >> m;
    while (m--) {
        int s, e;
        cin >> s >> e;
        if (road[s][e]){
            cout << -1 << '\n';
        }else if (road[e][s]){
            cout << 1 << '\n';
        }else cout << 0 <<'\n';
    }
    return 0;
}