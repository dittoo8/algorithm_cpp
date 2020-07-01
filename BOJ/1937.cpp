#include <cstdio>
#include <algorithm>
using namespace std;
const int dx[]={0,0,-1,1},dy[]={-1,1,0,0};
int n, a[501][501], d[501][501];
int dp(int x,int y){
    if (d[x][y]!=0) return d[x][y];
    d[x][y]=1;
    for(int i=0;i<4;i++){
        int nx = x+dx[i], ny = y+dy[i];
        if (nx < 0 || nx >= n || ny <0 || ny>=n ) continue;
        if (a[x][y] < a[nx][ny]){
            d[x][y] = max(d[x][y],dp(nx,ny)+1);
        }
    }
    return d[x][y];
}
int main(){
    int ans = 0;
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d", &a[i][j]);
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            ans = max(ans, dp(i,j));
        }
    }
    printf("%d\n", ans);
    return 0;
}