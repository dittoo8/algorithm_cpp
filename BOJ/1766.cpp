#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define MAX 32001
using namespace std;
vector<int> adj[MAX];
int inDegree[MAX];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n,m,a,b;
    cin >> n >> m;
    for(int i=0;i<m;i++){
        cin >> a >> b;
        adj[a].push_back(b);
        inDegree[b]++;
    }
    priority_queue<int, vector<int>, greater<int> > pq;
    for(int i=1;i<=n;i++){
        if(inDegree[i] == 0) {
            pq.push(i);
        }
    }
    for(int t = 0;t<n;t++){
        int now = pq.top();
        pq.pop();
        cout << now << ' ';
        for(int i=0;i<adj[now].size();i++){
            int next = adj[now][i];
            if(--inDegree[next] == 0){
                pq.push(next);
            }
        }
    }
    return 0;
}