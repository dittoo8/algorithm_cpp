#include <cstdio>
#include <vector>
#include <queue>
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
void bfs(int start){
    queue<int> q;
    q.push(start);
    a[start] = true;
    while(!q.empty()){
        int x = q.front();
        q.pop();
        for(int i=0;i<V[x].size();i++){
            int next = V[x][i];
            if(!a[next]) {
                q.push(next);
                a[next] = true;
            }
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
            // dfs(i);
            bfs(i);
            cnt++;
        }
    }
    printf("%d", cnt);
    return 0;
    
}