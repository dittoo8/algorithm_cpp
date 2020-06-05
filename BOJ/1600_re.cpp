#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;
struct monkey{
    int x,y,jump;
};
int h,w,k;
const int dx[]={0,0,1,-1,-2,-1,1,2,2,1,-1,-2};
const int dy[]={1,-1,0,0,1,2,2,1,-1,-2,-2,-1};
const int cost[] = {0,0,0,0,1,1,1,1,1,1,1,1};
int a[201][201];
int dist[201][201][31];
int main(){
    scanf("%d", &k);
    scanf("%d %d", &w, &h);
    memset(dist,-1,sizeof(dist));
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            scanf("%d", &a[i][j]);
        }
    }
    queue<monkey> q;
    q.push({0,0,0});
    dist[0][0][0]=0;
    while(!q.empty()){
        int x=q.front().x, y =q.front().y;
        int jump=q.front().jump; q.pop();
        for(int i=0;i<12;i++){
            int nx = x+dx[i], ny = y+dy[i], nc = jump+cost[i];
            if (0<=nx &&nx<h && 0<=ny && ny<w) {
                if (a[nx][ny]) continue;
                if (nc <=k) {
                    if (dist[nx][ny][nc]==-1){
                        dist[nx][ny][nc] = dist[x][y][jump]+1;
                        q.push({nx,ny,nc});
                    }
                }
            }
        }
    }
    int ans = -1;
    for(int i=0;i<=k;i++){
        if(dist[h-1][w-1][i]==-1) continue;
        if(ans==-1 || ans > dist[h-1][w-1][i]){
            ans = dist[h-1][w-1][i];
        }
    }
    printf("%d\n",ans);
    return 0;
}
