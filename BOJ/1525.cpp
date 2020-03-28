#include <iostream>
#include <string>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;
queue<int> q;
map<int, int> dist;
const int dx[] = {-1,0,1,0}, dy[] = {0,-1,0,1};
void bfs(){
    while(!q.empty()){
        int d = q.front(); q.pop();
        if(d == 123456789) {
            cout << dist[d] << endl;
            return;
        }
        string s = to_string(d);
        int k = s.find('9');
        int x = k/3, y = k%3;
        for(int i=0;i<4;i++){
            int nx = x+dx[i], ny = y+dy[i];
            if (nx <0 || nx >=3 || ny <0 || ny>=3) continue;
            int nk = nx*3 + ny;
            string ns = s;
            swap(ns[k],ns[nk]);
            int nd = stoi(ns);
            if(!dist[nd]){
                dist[nd] = dist[d]+1;
                q.push(nd);
            }
        }
    }
    cout << "-1\n" ;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m=0;
    for(int i=0;i<9;i++){
        cin >> n;
        if(!n) n=9;
        m = m*10+n;
    }
    q.push(m);
    bfs();
    return 0;
}