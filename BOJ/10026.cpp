#include <string>
#include <iostream>
using namespace std;
 
int n, a[2][101][101], dx[] = { 0,0,1,-1 }, dy[] = { 1,-1,0,0 }, cnt[2];
 
void dfs(int x, int y, int p, int c) {
    a[p][x][y] = -1;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx < 0 || ny < 0 || nx >= n || ny >= n || a[p][nx][ny] != c) continue;
        dfs(nx, ny, p, c);
    }
}
 
int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < n; j++) {
            if (s[j] == 'B') a[0][i][j] = a[1][i][j] = 1;
            else if (s[j] == 'R') a[0][i][j] = a[1][i][j] = 2;
            else if (s[j] == 'G') a[0][i][j] = 2, a[1][i][j] = 3;
        }
    }
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) for (int k = 0; k < 2; k++) {
        if (a[k][i][j] != -1) {
            dfs(i, j, k, a[k][i][j]);
            cnt[k]++;
        }
    }
    cout << cnt[1] << " " << cnt[0] << '\n';
    return 0;
}
