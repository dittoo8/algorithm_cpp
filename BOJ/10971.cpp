#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
int n, a[11][11],res=1e9;
bool ck[11];
vector<pair<int, int> > v[11];
void dfs(int start, int now,int len,int cost){
    if(len == n){
        if (a[now][start]==0) return;
        for(int i=1;i<=n;i++){
            if(!ck[i]) return;
        }
        cost+=a[now][start];
        if (res > cost) res = cost;
    }else {
        for(int i=0;i<(int)v[now].size();i++){
            if (ck[v[now][i].second]) continue;
            ck[v[now][i].second]=true;
            dfs(start,v[now][i].second,len+1,cost+v[now][i].first);
            ck[v[now][i].second]=false;
        }
    }
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            scanf("%d", &a[i][j]);
            if (i==j || a[i][j]==0) continue;
            v[i].push_back(make_pair(a[i][j],j));
        }
        sort(v[i].begin(), v[i].end());
    }
    for(int i=1;i<=n;i++){
        memset(ck,0,sizeof(ck));
        ck[i]=true;
        dfs(i,i,1,0);
    }
    printf("%d\n",res);
    return 0;
}