#include <iostream>
#include <queue>
using namespace std;
const int MAX = 1e6;
int n,k;
int dist[MAX+1];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    queue<int> q;
    q.push(n);
    int ans = 0, cnt = 0;
    while(!cnt){
        int Qsize = q.size();
        while(Qsize--){
            int now = q.front(); q.pop();
            if (now==k) cnt+=1;
            int nx[]={now-1, now+1, 2*now};
            for(int i=0;i<3;i++){
                if (nx[i]<0 || nx[i] > MAX) continue;
                if (dist[nx[i]] && dist[nx[i]]!=dist[now]+1) continue;
                q.push(nx[i]);
                dist[nx[i]] = dist[now] + 1;
            }
        }
        ans+=1;
    }
    cout << ans-1 << endl;
    cout << cnt << endl;
    return 0;
}