#include <iostream>
#include <cstring>
using namespace std;
int a[501];
//a[i] = 위에서 i 번째 높이에 있는 가로선
int d[501][501];
// d[i][j] = i번째 가로선까지 고려했을때, start에서 j까지 가는 최소비용
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> m >> n;
    int start, end, del, add;
    cin >> start >> end >> del >> add;
    start -= 1;
    end -= 1;
    for (int i=1; i<=n; i++) {
        cin >> a[i];
        a[i] -= 1;
    }
    for (int i=1; i<=n; i++) {
        for (int j=0; j<m; j++) {
            d[i][j] = 1000000000;
        }
    }
    //가로선을 하나도 고려하지 않았을 때
    for (int i=0; i<m; i++) {
        if (i == start) {
            d[0][i] = 0;
        } else {
            d[0][i] = abs(start - i) * add;
        }
    }
    for (int i=1; i<=n; i++) { //고려하는 가로선의 갯수 i
        for (int j=0; j<m; j++) { //출발점 j
            for (int k=0; k<m; k++) { //도착점 k
                if (k == j && (a[i] == k || a[i]+1 == k)) {
                    //출발점과 도착점이 같으면 사이에 있는 가로선을 모두 제거해야함
                    if (d[i][j] > d[i-1][k] + del) {
                        d[i][j] = d[i-1][k] + del;
                    }
                } else if ((k <= a[i] && a[i] <= j-1) || (j <= a[i] && a[i] <= k-1)) {
                    if (d[i][j] > d[i-1][k] + (abs(k-j)-1)*add) {
                        d[i][j] = d[i-1][k] + (abs(k-j)-1)*add;
                    }
                } else {
                    if (d[i][j] > d[i-1][k] + abs(k-j)*add) {
                        d[i][j] = d[i-1][k] + abs(k-j)*add;
                    }
                }
            }
        }
    }
    cout << d[n][end] << '\n';
    return 0;
}