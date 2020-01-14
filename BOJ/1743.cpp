#include <cstdio>
#include <algorithm>
using namespace std;
int n,m,k;
char h[102][102] = {'.',};
bool check[102][102] = {false,};
const int dx[] = {-1, 1, 0,0}, dy[] = {0,0,-1,1};
int cnt = 0;
int dfs(int x,int y){
    int temp = 1;
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            int nx = x+dx[i], ny = y+dy[i];
            if(nx<=0 || nx>n || ny<=0 ||ny>m) continue;
            if(h[nx][ny]=='#' && !check[nx][ny]) {
                check[nx][ny] = true;
                temp += dfs(nx,ny);
            }
        }
    }
    return temp;
}
int solve(){
    
    for(int i=1; i<=n;i++){
        for(int j=1;j<=m;j++){
            if(h[i][j]=='#' && !check[i][j]) {
                check[i][j]= true;
                cnt = max(cnt, dfs(i,j));
            }
        }
    }
    return cnt;
}
int main(){
    scanf("%d %d %d", &n, &m, &k);
    while(k--){
        int a, b;
        scanf("%d %d", &a, &b);
        h[a][b] = '#';
    }
    printf("%d",solve());
    return 0;
}