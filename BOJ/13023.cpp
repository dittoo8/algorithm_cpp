#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
vector<int> v[2002];
bool c[2002];
int n,m;
bool dfs(int x, int cnt){
    if(cnt == 5) return true;
    c[x] = true;
    for(int i=0;i<v[x].size();i++){
        int now = v[x][i];
        if(c[now]) continue;
        //방문했을때 넘김
        if(dfs(now, cnt+1)) {
            return true;
        }
    }
    c[x] = false;
    return false;
}
int main(){
    scanf("%d %d", &n ,&m);
    for(int i=0;i<m;i++){
        int a, b;
        scanf("%d %d", &a, &b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for(int i=0;i<n;i++){
        if(dfs(i,1)) {
            printf("1");
            return 0;
        }
    }
    printf("0");
    return 0;
}