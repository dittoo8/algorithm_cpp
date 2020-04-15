#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;
int a[51][51];
bool visit[51][51];
int n,l,r,idx=1,tsum,tcnt;
vector<pair<int, int> > v;
const int dx[] = {-1,0,1,0}, dy[] = {0,-1,0,1};
void dfs(int x,int y){
    tcnt++;
    visit[x][y]=true;
    tsum+=a[x][y];
    v.push_back(make_pair(x,y));
    for(int i=0;i<4;i++){
        int nx = x+dx[i], ny = y+dy[i];
        if (nx<0 || nx >=n || ny <0 || ny >=n || visit[nx][ny]) continue;
        if (abs(a[nx][ny]-a[x][y])>=l && abs(a[nx][ny]-a[x][y])<=r){
            dfs(nx,ny);
        }
    }
    return;
}
int main(){
    scanf("%d %d %d",&n, &l, &r);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d", &a[i][j]);
        }
    }
    int res=0;
    bool ck=true;
    while(ck){
        ck=false;
        memset(visit,0,sizeof(visit));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if (!visit[i][j]){
                    v.clear();
                    tsum=0;
                    tcnt=0;
                    dfs(i,j);
                }
                if (v.size()>1){
                    ck=true;
                    int p = tsum/tcnt;
                    while(!v.empty()){
                        int nowi= v.back().first;
                        int nowj = v.back().second;

                        v.pop_back();
                        a[nowi][nowj]=p;
                    }
                }
            }
        }
        res++;
    }
    printf("%d\n",res-1);
    return 0;
}