#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
const int MAX = 1e6;
int n,k,dist[MAX];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    memset(dist,-1, sizeof(dist));
    cin >> n >> k;
    dist[n] = 0;
    // ** 초기 코드 (큐 사용)
    // queue<int> q;
    // q.push(n);
    // while(!q.empty()){
    //     int now = q.front(); q.pop();
    //     if (now == k) {
    //         cout << dist[now] << endl;
    //         exit(0);
    //     }
    //     int nx[]= {now*2,now-1,now+1};
    //     int ny[] = {dist[now], dist[now]+1, dist[now]+1};
    //     for(int i=0;i<3;i++){
    //         if (nx[i] < 0 || nx[i] > MAX || dist[nx[i]]>=0) continue;
    //         q.push(nx[i]);
    //         dist[nx[i]] = ny[i];
    //     }
    // }

    // ** 개선 코드 (덱 사용), 순간이동에 우선순위
    deque<int> dq;
    dq.push_back(n);
    while(!dq.empty()){
        int now = dq.front(); dq.pop_front();
        if (now == k) {
            cout << dist[now] << endl;
            exit(0);
        }
        int nx[]= {now*2,now-1,now+1};
        for(int i=0;i<3;i++){
            if (nx[i] < 0 || nx[i] > MAX || dist[nx[i]]>=0) continue;
            if (i==0){
                dq.push_front(nx[i]);
                dist[nx[i]] = dist[now];
            } else {
                dq.push_back(nx[i]);
                dist[nx[i]] = dist[now]+1;
            }
        }

    }

    
    return 0;
}