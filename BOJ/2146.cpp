#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;
int n, a[101][101],id=1,ans=1e6;
bool visit[101][101];
int dx[]= {-1,0,1,0}, dy[] = {0,1,0,-1};
vector<pair<int, int> > v[10001];
void calcDist(int s, int e){
    int tmp;
    for(int i=0;i<v[s].size();i++){
        for(int j=0;j<v[e].size();j++){
            tmp = abs(v[s][i].first-v[e][j].first) + abs(v[s][i].second-v[e][j].second);
            if (tmp < ans) ans =tmp;
        }
    }
}
void dfs(int x, int y){
    visit[x][y]=true;
    a[x][y]=id;
    for(int i=0;i<4;i++){
        int nx = x+dx[i],ny=y+dy[i];
        if (visit[nx][ny] || nx <0 || nx >= n || ny <0 || ny>=n) continue;
        else if (!a[nx][ny]){
            v[id].push_back(make_pair(nx,ny));
        } else dfs(nx,ny);
    }
}
int main(){
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%1d",&a[i][j]);
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if (a[i][j] && !visit[i][j]){
                dfs(i,j);
                id++;
            }
        }
    }
    for(int i=1;i<id;i++){
        for(int j=i+1;j<id;j++){
            calcDist(i,j);
        }
    }
    printf("%d\n",ans+1);
    return 0;
}