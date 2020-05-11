#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
struct shark{
    int d,x,y;
    // Min heap (priority : dist > x > y)
    bool operator < (const shark &t) const {
        if (d==t.d){
            if(x == t.x) return y > t.y;
            else return x > t.x;
        }else return d>t.d;
    }
};
int n,ans,a[20][20];
bool ck[20][20];
const int dx[]={-1,0,0,1}, dy[]={0,-1,1,0};
int fish[7],body=2,eat=0,rtime=0;
priority_queue<shark> q;
void bfs(){
    while(!q.empty()){
        int d = q.top().d;
        int x = q.top().x;
        int y = q.top().y;
        q.pop();
        if(0< a[x][y] && a[x][y]<body){
            a[x][y]=0;
            eat++;
            if(eat==body){
                body++;
                eat=0;
            }
            ans+=d;
            d=0;
            memset(ck,false,sizeof(ck));
            while(!q.empty()) q.pop();
        }
        for(int i=0;i<4;i++){
            int nx = x+dx[i],ny=y+dy[i];
            if (nx<0 || nx >=n || ny <0 || ny>=n) continue;
            if (ck[nx][ny]) continue;
            if(0<a[nx][ny] && a[nx][ny] > body) continue;
            q.push({d+1, nx,ny});
            ck[nx][ny]=true;
        }
    }
}
void solve(){
    body = 2;
    bfs();
    printf("%d\n",ans);
}
int main(){
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d", &a[i][j]);
            if(a[i][j]==9){
                q.push({0,i,j});
                a[i][j]=0;
            }
        }
    }
    solve();
    return 0;
}