#include <iostream>
#include <vector>
#define MAX 101
using namespace std;
int a[MAX][MAX];
long long d[MAX][MAX][3];
int n;
long long go(int x, int y, int dir){
    if(x==n-1 && y== n-1) return 1;
    long long &ans = d[x][y][dir];
    if (ans != -1) return ans;
    ans = 0;
    if (dir == 0) { // -
        if (y+1 < n && a[x][y+1] == 0) {
            ans += go(x, y+1, 0);
        }
        if (x+1 < n && y+1 < n && a[x][y+1] == 0 && a[x+1][y] == 0 && a[x+1][y+1] == 0) {
            ans += go(x+1, y+1, 1);
        }
    } else if (dir == 1) { // dig
        if (y+1 < n && a[x][y+1] == 0) {
            ans += go(x, y+1, 0);
        }
        if (x+1 < n && a[x+1][y] == 0) {
            ans += go(x+1, y, 2);
        }
        if (x+1 < n && y+1 < n && a[x][y+1] == 0 && a[x+1][y] == 0 && a[x+1][y+1] == 0) {
            ans += go(x+1, y+1, 1);
        }
    } else if (dir == 2) { // |
        if (x+1 < n && a[x+1][y] == 0) {
            ans += go(x+1, y, 2);
        }
        if (x+1 < n && y+1 < n && a[x][y+1] == 0 && a[x+1][y] == 0 && a[x+1][y+1] == 0) {
            ans += go(x+1, y+1, 1);
        }
    }
    return ans;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> a[i][j];
        }
    }
    fill(&d[0][0][0], &d[n][n][2]+1,-1);
    cout << go(0,1,0) << '\n';
    return 0;
}