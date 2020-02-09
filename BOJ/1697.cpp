#include <iostream>
#include <queue>
#define MAX 100000
using namespace std;
int n,k;
int dist[MAX+1];
void bfs(){
    queue<int> q;
    q.push(n);
    while(1){
        int x = q.front();
        q.pop();
        if(x == k) {
            cout << dist[x] << endl;
            return;
        }
        int arr[3] = {x-1, x+1, x*2};
        for(int i=0;i<3;i++){
            int nx = arr[i];
            if (nx <0 || nx > MAX) continue;
            if (dist[nx]) continue;
            q.push(nx);
            dist[nx] = dist[x]+1;
        }
    }
}
int main(){
    cin >> n >> k;
    bfs();
    return 0;
}