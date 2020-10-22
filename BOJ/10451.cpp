#include <iostream>
#define MAX 1001
using namespace std;
int adj[MAX];
bool visit[MAX];
void dfs(int x){
    if(visit[x]) return; // 이미 방문한 정점을 또 방문하면 cycle
    visit[x] = true;
    dfs(adj[x]);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc,n,ans;
    cin >> tc;
    while(tc--){
        cin >> n;
        ans = 0;
        fill(&visit[0],&visit[n]+1,0);
        for(int i=1;i<=n;i++){
            cin >> adj[i];
        }
        for(int i=1;i<=n;i++){
            if(!visit[i]){
                dfs(i);
                ans++;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}