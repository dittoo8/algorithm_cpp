#include <cstdio>
using namespace std;
int n,m,ans;
int a[501][501];
bool c[501][501];
const int dx[] = {0,0,1,-1};
const int dy[] = {1,-1,0,0};
void go(int x, int y, int sum, int cnt){
    if (cnt == 4) {
        if (ans < sum) ans = sum;
        return;
    }
    if (x < 0 || x >=n || y<0 || y >=m) return;
    if (c[x][y]) return;
    c[x][y]=true;
    for(int k=0;k<4;k++){
        go(x+dx[k],y+dy[k],sum+a[x][y],cnt+1);
    }
    c[x][y]= false;
}
int main(){
    scanf("%d %d", &n, &m);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d", &a[i][j]);
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            go(i,j,0,0);
            if (j+2 < m) { // ㅗ
                int tmp = a[i][j]+a[i][j+1]+a[i][j+2];
                if (i-1 >= 0 ){
                    int tmp2 = tmp+ a[i-1][j+1];
                    if (ans < tmp2) ans = tmp2;
                }
                if (i+1 < n ){ // ㅜ
                    int tmp2 = tmp+ a[i+1][j+1];
                    if (ans < tmp2) ans = tmp2;
                }
            }
            if (i+2 <n){ // ㅏ
                int tmp = a[i][j]+a[i+1][j]+a[i+2][j];
                if (j+1 < m){
                    int tmp2 = tmp+a[i+1][j+1];
                    if (ans < tmp2) ans = tmp2;
                }
                if (j-1 >= 0){ // ㅓ
                    int tmp2 = tmp+a[i+1][j-1];
                    if (ans < tmp2) ans = tmp2;
                }
            }
        }
    }
    
    printf("%d\n", ans);
    return 0;
}