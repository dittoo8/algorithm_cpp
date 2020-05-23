#include <cstdio>
#include <bitset>
using namespace std;
int map[51][51][4]; // (x,y)
int a[51][51];
const int dx[]= {0,-1,0,1}, dy[]={-1,0,1,0};
int n,m,roomcnt,mxroomsize,removemx,cnt;
int visit[51][51];
int roomidx[51];
void dfs(int x, int y){
    cnt++;
    visit[x][y]=roomcnt;
    for(int i=0;i<4;i++){
        if (map[x][y][i]) continue;
        int nx = x+dx[i], ny= y +dy[i];
        if(nx <0 || nx >=n || ny <0 || ny>= m ||visit[nx][ny]) continue;
        dfs(nx,ny);
    }
}
int main(){
    scanf("%d %d", &m, &n);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            bitset<4> bits;
            scanf("%d",&a[i][j]);
            bits = a[i][j];
            if(bits[3]) map[i][j][3]=true;
            if(bits[2]) map[i][j][2]=true;
            if(bits[1]) map[i][j][1]=true;
            if(bits[0]) map[i][j][0]=true;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!visit[i][j]){
                roomcnt++;
                dfs(i,j);
                if(cnt > mxroomsize) mxroomsize = cnt;
                roomidx[roomcnt]=cnt;
                cnt=0;
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            for(int k=0;k<4;k++){
                int nx = i+dx[k], ny = j+dy[k];
                if (nx <0|| nx >=n || ny <0 || ny >=m) continue;
                if(visit[i][j]==visit[nx][ny]) continue;
                if(roomidx[visit[i][j]]+roomidx[visit[nx][ny]]>removemx) {
                    removemx = roomidx[visit[i][j]]+roomidx[visit[nx][ny]];
                }
            }
        }
    }
    printf("%d\n%d\n%d\n",roomcnt,mxroomsize,removemx);
    return 0;
}