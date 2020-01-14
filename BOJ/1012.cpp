#include <cstdio>
#include <cstring>
using namespace std;
int t,m,n,k,ans;
bool check[52][52];
int a[52][52];
const int dx[] = {-1, 1, 0,0}, dy[] = {0,0,-1,1};
void dfs(int x, int y){
    check[x][y] = true;
    for(int i=0;i<4;i++){
        int nx = x+dx[i], ny = y+dy[i];
        if(nx<0 || nx>=n || ny<0 ||ny>=m) continue;
        if(a[nx][ny] && !check[nx][ny]) {
            dfs(nx,ny);
        }
    }
}
void solve(){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if (a[i][j] && !check[i][j]){
                //벌레가 있고, 체크가 안된 부분일때
                dfs(i,j);
                ans++;
            }
        }
    }
}
int main(){
    scanf("%d", &t); //testcase
    while(t--){
        ans = 0;
        memset(check, 0, sizeof(check));
        memset(a, 0, sizeof(a));
        scanf("%d %d %d", &m, &n, &k);
        for(int i=0;i<k;i++){
            int x, y;
            scanf("%d %d", &x, &y);
            a[y][x] = 1;
        }
        solve();
        printf("%d\n", ans);
    }
    return 0;
}