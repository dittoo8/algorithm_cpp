#include <cstdio>
using namespace std;
int n,m,x,y,k;
int a[21][21];
int dice[6], tmp[6];
const int dir[4][6] = {
    {2,1,5,0,4,3},
    {3, 1, 0, 5, 4, 2},
    {4, 0, 2, 3, 5, 1},
    {1, 5, 2, 3, 0, 4}
};
const int dx[] = {0,0,-1,1}, dy[] = {1,-1,0,0};
void sol(){
    while(k--){
        int d;
        scanf("%d",&d); d--;
        if(x+dx[d]<0 || x+dx[d]>=n || y+dy[d] <0 || y+dy[d] >=m) continue;
        x+=dx[d], y+=dy[d];
        for(int i=0;i<6;i++){
            tmp[i]=dice[i];
        }
        for(int i=0;i<6;i++){
            dice[i]=tmp[dir[d][i]];
        }
        if(a[x][y]){
            dice[5]=a[x][y];
            a[x][y]=0;
        }else {
            a[x][y]=dice[5];
        }
        printf("%d\n",dice[0]);
    }
}
int main(){
    scanf("%d %d %d %d %d", &n, &m, &x, &y, &k);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d", &a[i][j]);
        }
    }
    sol();
    return 0;
}