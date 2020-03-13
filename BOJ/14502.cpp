#include <cstdio>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;
int n,m,ans,safe;
vector<pair<int, int> > vi;
int a[9][9];
int dx[] = {-1,0,0,1}, dy[]={0,1,-1,0};
bool ck[9][9];
int dfs(int x,int y){
    int res = 1;
    ck[x][y]=true;
    for(int i=0;i<4;i++){
        int nx = x+dx[i],ny=y+dy[i];
        if(nx<0 || nx>=n || ny <0 || ny >=m) continue;
        if(a[nx][ny]==0 && !ck[nx][ny]){
            res+=dfs(nx,ny);
        }
    }
    return res;
}
void buildWall(int wall,int x, int y){
    if(wall==3){
        int tmp=safe;
        memset(ck,0,sizeof(ck));
        for(int i=0;i<vi.size();i++){
            if(ck[vi[i].first][vi[i].second]) continue;
            tmp-=dfs(vi[i].first,vi[i].second);
        }
        if(tmp > ans) ans = tmp;
        return;
    }
    for(int i=x;i<n;i++){
        int k=i == x ? y:0;
        for(int j=k;j<m;j++){
            if(a[i][j]==0){
                a[i][j]=1;
                buildWall(wall+1,i,j+1);
                a[i][j]=0;
            }
        }
    }
}
int main(){
    scanf("%d %d",&n,&m);
    safe = n*m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%1d",&a[i][j]);
            if(a[i][j]==1) safe--;
            if(a[i][j]==2) {
                vi.push_back(make_pair(i,j));
            }
        }
    }
    safe-=3;
    buildWall(0,0,0);
    printf("%d\n",ans);
    return 0;
}