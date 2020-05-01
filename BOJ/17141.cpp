#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
int n,m,k,res=1e9;
int a[51][51], dist[51][51];
bool visit[11];
const int dx[] = {-1, 0 , 1, 0}, dy[] = {0, 1, 0, -1};
vector<pair<int, int> > vi;
queue<pair<int, int> > q;
void bfs(){
    int infect=0, times=0;
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        times = dist[x][y];
        for(int i=0;i<4;i++){
            int nx=x+dx[i],ny=y+dy[i];
            if (nx <0 || nx >=n || ny <0 || ny>=n) continue;
            if (dist[nx][ny]==-1 && a[nx][ny]!=1){
                dist[nx][ny]=dist[x][y]+1;
                q.push(make_pair(nx,ny));
                infect+=1;
            }
        }
    }
    if (infect == k && res > times) res = times;
}
void solve(int idx, int cnt,int d){
    if (cnt==m){
        memset(dist,-1,sizeof(dist));
        for(int i=0;i<d;i++){
            if (visit[i]){
                q.push(make_pair(vi[i].first,vi[i].second));
                dist[vi[i].first][vi[i].second] = 0;
            }
        }
        bfs();
        return;
    }
    for(int i=idx;i<d;i++){
        if (!visit[i]) {
            visit[i]=true;
            solve(i+1,cnt+1,d);
            visit[i]=false;
        }
    }
}
int main(){
    scanf("%d %d", &n, &m);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&a[i][j]);
            if (a[i][j]==2){
                //초기 바이러스 가능
                vi.push_back(make_pair(i,j));
            }else if (a[i][j]==0){
                //빈칸
                k+=1;
            }
        }
    }
    k=k+(int)vi.size()-m;
    solve(0,0,(int)vi.size());
    printf("%d\n",res==1e9?-1:res);
    return 0;
}