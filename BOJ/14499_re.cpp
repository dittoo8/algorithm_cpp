#include <cstdio>
using namespace std;
int map[20][20];
int dice[7];
int op[1001];
int n,m,x,y,k;
const int dx[]={0,0,-1,1}, dy[]= {1,-1,0,0};
int main(){
    scanf("%d %d %d %d %d", &n, &m, &x, &y, &k);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d", &map[i][j]);
        }
    }
    for(int i=0;i<k;i++){
        scanf("%d", &op[i]);
        op[i]--;
    }
    for(int i=0;i<k;i++){
        int nx = x+dx[op[i]], ny=y+dy[op[i]];
        if(nx <0 || nx >= n || ny <0 || ny >= m ) continue;
        if(op[i]==0){
            int tmp =dice[1];
            dice[1]=dice[4];
            dice[4]=dice[6];
            dice[6]=dice[3];
            dice[3]=tmp;
        }else if (op[i]==1){
            int tmp =dice[1];
            dice[1]=dice[3];
            dice[3]=dice[6];
            dice[6]=dice[4];
            dice[4]=tmp;
        }else if (op[i]==2){
            int tmp =dice[1];
            dice[1]=dice[5];
            dice[5]=dice[6];
            dice[6]=dice[2];
            dice[2]=tmp;
        }else {
            int tmp =dice[1];
            dice[1]=dice[2];
            dice[2]=dice[6];
            dice[6]=dice[5];
            dice[5]=tmp;
        }
        x = nx; y=ny;
        if(map[x][y]==0){
            map[x][y]=dice[6];
        }else {
            dice[6]=map[x][y];
            map[x][y]=0;
        }
        printf("%d\n", dice[1]);
    }
    
    return 0;
}