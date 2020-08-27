#include <iostream>
#include <queue>
#define MAX 1000001
using namespace std;
int f,s,g,u,d;
int dist[MAX];
int main(){
    cin >> f >> s >> g >> u >> d;
    queue<int> q;
    fill(&dist[0],&dist[f]+1,-1);
    dist[s] = 0;
    q.push(s);
    while(!q.empty()){
        int x = q.front();
        q.pop();
        if (x == g) break;
        if (x+u <=f){
            if (dist[x+u]==-1 || dist[x+u]> dist[x]+1) {
                q.push(x+u);
                dist[x+u]= dist[x]+1;
            }
        }
        if (x-d >=1 ){
            if (dist[x-d]==-1|| dist[x-d] > dist[x]+1){
                q.push(x-d);
                dist[x-d]=dist[x]+1;
            }
        }
    }
    if (dist[g]!=-1){
        cout << dist[g] << '\n';
    }else cout << "use the stairs" << '\n';
    return 0;
}