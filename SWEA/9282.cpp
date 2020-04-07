#include <cstdio>
#include <cstring>
using namespace std;
const int MAXI = 51;
int sum[MAXI][MAXI];
int choco[MAXI][MAXI];
int dp[MAXI][MAXI][MAXI][MAXI];
int solve(int x,int y, int ex, int ey){
    if(x==ex && y ==ey) return 0;
    if(dp[x][y][ex][ey]!=-1) return dp[x][y][ex][ey];
    int cnt = sum[ex][ey]-sum[x-1][ey]-sum[ex][y-1]+sum[x-1][y-1];
    int rt = 1e9;
    for(int i=x;i<ex;i++){
        int tmp = solve(x,y,i,ey) + solve(i+1,y,ex,ey);
        if(rt > tmp +cnt) rt = tmp+cnt;
    }
    for(int i=y;i<ey;i++){
        int tmp = solve(x,y,ex,i) + solve(x,i+1,ex,ey);
        if(rt > tmp +cnt) rt = tmp+cnt;
    }
    return dp[x][y][ex][ey]=rt;
}
int main(){
    int tc;
    scanf("%d",&tc);
    for(int i=1;i<=tc;i++){
        int res,n,m;
        memset(dp,-1,sizeof(dp));
        scanf("%d %d", &n, &m);
        for(int j=1;j<=n;j++){
            for(int k=1;k<=m;k++){
                scanf("%d",&choco[j][k]);
            }
        }

        for(int j=1;j<=n;j++){
            for(int k=1;k<=m;k++){
                sum[j][k]=sum[j-1][k]+sum[j][k-1]-sum[j-1][k-1]+choco[j][k];
            }
        }
        res = solve(1,1,n,m);
        printf("#%d %d\n",i,res);
    }
    return 0;
}