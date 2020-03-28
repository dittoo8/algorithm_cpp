#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 1e6;
int n,k;
int dist[MAX+1],path[MAX+1];
void bfs(){
    queue<int> q;
    q.push(n);
    while (!q.empty()){
        int x= q.front();q.pop();
        if (x==k){
            printf("%d\n",dist[x]);
            vector<int> p;
            while(x!=n){
                p.push_back(x);
                x = path[x];
            }
            p.push_back(n);
            reverse(p.begin(),p.end());
            for(int i=0;i<(int)p.size();i++){
                printf("%d ",p[i]);
            }
            printf("\n");
            return;
        }
        int dx[3] = {x-1,x+1, x*2};
        for(int i=0;i<3;i++){
            if (dx[i]<0 || dx[i]>MAX) continue;
            if (dist[dx[i]]) continue;
            q.push(dx[i]);
            dist[dx[i]]= dist[x]+1;
            path[dx[i]]=x;
        }
    }
}
int main(){
    scanf("%d %d", &n, &k);
    bfs();
    return 0;
}