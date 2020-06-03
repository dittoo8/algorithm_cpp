#include <cstdio>
using namespace std;
int n,m,x,y,d,cnt;
int map[51][51];
const int dx[]={-1,0,1,0},dy[]={0,1,0,-1};
int main(){
    scanf("%d %d", &n, &m);
    scanf("%d %d %d", &x, &y, &d);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%1d", &map[i][j]);
        }
    }
    while(true){
        if(map[x][y]==0) map[x][y]=2; // 1.
        if(map[x-1][y]!=0 && map[x+1][y]!=0 && map[x][y-1] !=0 && map[x][y+1]!=0){
            //네 방향 청소가 되었거나, 벽일때 (2.c,2.d)
            
            if(map[x-dx[d]][y-dy[d]]==1) break; // 2.d
            else x-=dx[d],y-=dy[d]; //2.c
        }else {
            d= (d+3)%4; //2.a,2.b 왼쪽방향으로 회전
            if(map[x+dx[d]][y+dy[d]]==0) x+=dx[d], y+=dy[d]; //2.a
        }
    }

    //청소한 영역 갯수 세기
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(map[i][j]==2) cnt+=1;
        }
    }
    printf("%d\n", cnt);
    return 0;
}