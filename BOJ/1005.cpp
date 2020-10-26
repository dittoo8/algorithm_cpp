#include <iostream>
#include <queue>
#include <vector>
#define MAX 10001
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    vector<int> adj[MAX];
    int inDegree[MAX],d[MAX],costs[MAX];
    int tc,n,k,w;
    cin >> tc;
    for(int t=0;t<tc;t++){
        cin >> n >> k;
        fill(&inDegree[0], &inDegree[n]+1,0);
        fill(&d[0], &d[n]+1,0);
        fill(&costs[0], &costs[n]+1,0);
        for(int i=1;i<=n;i++){
            cin >> d[i];
            adj[i].clear();
        }
        int x,y,answer = 0;
        for(int i=0;i<k;i++){
            cin >> x >> y;
            adj[x].push_back(y);
            inDegree[y]++;
        }
        cin >> w;
        queue<int> q;
        for(int i=1;i<=n;i++){
            if(inDegree[i]==0) {
                q.push(i);
                costs[i] = d[i];
            }
        }
        for(int i=1;i<=n;i++){
            int x = q.front();
            q.pop();
            for(int k=0;k<adj[x].size();k++){
                int next = adj[x][k];
                if(costs[next] < costs[x]+d[next]){
                    costs[next] = costs[x]+d[next];
                }
                if(--inDegree[next]==0){
                    q.push(next);
                }
            }
        }
        cout << costs[w] << '\n';
    }
    return 0;
}