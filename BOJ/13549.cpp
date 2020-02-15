#include <iostream>
#include <queue>
using namespace std;
const int MAX = 1e6;
int n,k,dist[MAX];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    memset(dist,-1, sizeof(dist));
    cin >> n >> k;
    queue<int> q;
    q.push(n);
    dist[n] = 0;
    while(!q.empty()){
        int now = q.front(); q.pop();
        if (now == k) {
            cout << dist[now] << endl;
            exit(0);
        }
        int nx[]= {now*2,now-1,now+1};
        int ny[] = {dist[now], dist[now]+1, dist[now]+1};
        for(int i=0;i<3;i++){
            if (nx[i] < 0 || nx[i] > MAX || dist[nx[i]]>=0) continue;
            q.push(nx[i]);
            dist[nx[i]] = ny[i];
            // cout << "nx : " <<nx[i] <<" dist : " << dist[nx[i]]<<  endl;
        }
    }
    return 0;
}