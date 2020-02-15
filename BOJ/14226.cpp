#include <iostream>
#include <queue>
using namespace std;
int n, dist[2001][2001];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    queue<pair<int, int> > q;
    q.push(make_pair(1,0));
    int cnt = 0;
    int clip = 0;
    while(!q.empty()){
        int now = q.front().first;
        int clip = q.front().second;
         if (now == n) {
            cout << dist[now][clip] << endl;
            exit(0);
        }
        q.pop();
        int nx[] = {now, now+clip, now-1};
        int ny[] = {now, clip, clip};
        for(int i=0;i<3;i++){
            if (nx[i]<0 || nx[i]>2*n) continue;
            //현재 이모티콘 수가 0보다 작거나, 현재수 2배보다 클 때
            if (dist[nx[i]][ny[i]]) continue;
            // 이미 더 작은 값으로 들어가 있는 경우
            q.push(make_pair(nx[i],ny[i]));
            dist[nx[i]][ny[i]] = dist[now][clip] + 1;
        }
    }
    return 0;
}