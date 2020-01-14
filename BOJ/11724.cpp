#include <cstdio>
#include <vector>
using namespace std;
int n,m;
vector<int> V[1001];
bool a[1001];
void dfs(int start){
    a[start] = true;
    for(int i=0;i<V[start].size();i++){
        int next = V[start][i];
        if(!a[next]) {
            dfs(next);
        }
    }
}
int main(){
    scanf("%d %d", &n,&m);
    while(m--){
        int a, b;
        scanf("%d %d", &a, &b);
        V[a].push_back(b);
        V[b].push_back(a);
    }
    int cnt=0;
    for(int i=1;i<=n;i++){
        while(!a[i]){
            dfs(i);
            cnt++;
        }
    }
    printf("%d", cnt);
    return 0;
    
}