#include <cstdio>
using namespace std;
#define MAX 51
int n,m,r,c,dir;
int a[MAX][MAX];
int res;
int dx[] = {-1,0,1,0}, dy[] = {0,1,0,-1};
void solve(){
    while(1){
        bool clean = false;
        for(int k=0;k<4;k++){
            int nd = (dir+3)%4;
            int nx = r+dx[nd], ny = c+dy[nd];
            dir=nd;
            if(!a[nx][ny]){
                a[nx][ny]=2;
                res++;
                r=nx,c=ny;
                clean = true;
                break;
            }
        }
        if(!clean){
            if(a[r-dx[dir]][c-dy[dir]]==1) return;
            else r-=dx[dir], c-=dy[dir];
        }
    }
}
int main(){
    scanf("%d %d",&n, &m);
    scanf("%d %d %d", &r, &c, &dir);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d",&a[i][j]);
        }
    }
    a[r][c] = 2;
    solve();
    printf("%d\n",res+1);
    return 0;
}