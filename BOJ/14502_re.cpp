#include <cstdio>
#include <cstring>
using namespace std;
const int dx[]={0,0,-1,1}, dy[]={-1,1,0,0};
int n,m,a[8][8];
bool ck[8][8];
int answer;
void dfs(int x, int y){
    ck[x][y]=true;
    for(int i=0;i<4;i++){
        int nx = x+dx[i], ny = y+dy[i];
        if (nx <0 || nx >=n || ny <0 || ny >=m) continue;
        if (a[nx][ny]!=1 && !ck[nx][ny]) dfs(nx,ny);
    }
}
void backtrack(int x, int y,int cnt){
    if (cnt ==3){
        memset(ck,false,sizeof(ck));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if (a[i][j]==2 && !ck[i][j]) dfs(i,j);
            }
        }
        int tsum=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if (a[i][j]!=1 && !ck[i][j]) tsum++;
            }
        }
        if (answer < tsum) answer = tsum;
        return;
    }
    for(int i=x;i<n;i++){
        int k = i==x?y:0;
        for(int j=k;j<m;j++){
            if (a[i][j]==0){
                a[i][j]=1;
                backtrack(i,j+1,cnt+1);
                a[i][j]=0;
            }
        }
    }
}
int main(){
    scanf("%d %d", &n, &m);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d", &a[i][j]);
        }
    }
    backtrack(0,0,0);
    printf("%d\n",answer);
    return 0;
}