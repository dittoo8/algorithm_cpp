#include <cstdio>
#include <queue>
using namespace std;
int n,res;
int a[17][17];
int moveD[3][2] = {{1,0},{0,1},{1,1}};
void solve(int x, int y, int pipe){
    if(x==n-1 && y == n-1){
        res++;
        return;
    }
    for(int i=0;i<3;i++){
        if ((i==0 && pipe ==1)|| (i==1 && pipe==0)) continue;
        int nextX = x+moveD[i][0];
        int nextY = y+moveD[i][1];
        if (nextX >=n || nextY>=n || a[nextX][nextY]) continue;
        if (i==2 && (a[x][y+1] || a[x+1][y])) continue;
        solve(nextX,nextY,i);

    }
}
int main(){
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%1d",&a[i][j]);
        }
    }
    solve(1,0,0);
    printf("%d\n", res);
    return 0;
}