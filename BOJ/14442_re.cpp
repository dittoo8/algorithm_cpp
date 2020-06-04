#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;
struct position {
    int x,y,wall;
};
int n,m,k;
int a[1001][1001];
int dist[1001][1001][11];
const int dx[]={0,-1,0,1},dy[]={-1,0,1,0};
int main(){
    scanf("%d %d %d", &n, &m, &k);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%1d", &a[i][j]);
        }
    }
    queue<position> q;
    q.push({0,0,0});
    dist[0][0][0]=1;
    while(!q.empty()){
        int x = q.front().x,y=q.front().y;
        int wall = q.front().wall;
        q.pop();
        for(int i=0;i<4;i++){
            int nx = x+dx[i],ny=y+dy[i];
            if(nx<0 || nx>=n || ny<0 ||ny>=m) continue;
            if(dist[nx][ny][wall]) continue;
            if(a[nx][ny]==1 && wall>=k) continue;
            dist[nx][ny][wall+a[nx][ny]]=dist[x][y][wall]+1;
            q.push({nx,ny,wall+a[nx][ny]});
        }
    }
    int ans=-1;
    for(int i=0;i<=k;i++){
        if(dist[n-1][m-1][i]==0) continue;
        if(ans==-1) ans = dist[n-1][m-1][i];
        else if (ans > dist[n-1][m-1][i]) ans = dist[n-1][m-1][i];
    }
    printf("%d\n",ans);
    return 0;
}