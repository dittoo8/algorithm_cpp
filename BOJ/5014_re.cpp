#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;
int dist[1000001];
int main(){
    memset(dist,-1,sizeof(dist));
    int f,s,g,u,d;
    scanf("%d %d %d %d %d", &f, &s, &g, &u, &d);
    queue<int> q;
    q.push(s);
    dist[s]=0;
    while(!q.empty()){
        int now = q.front();
        q.pop();
        if(now==g) break;
        if(now+u <=f &&(dist[now+u]==-1||dist[now+u]>dist[now]+1)){
            dist[now+u]= dist[now]+1;
            q.push(now+u);
        }
        if(now-d>=1 &&(dist[now-d]==-1||dist[now-d]>dist[now]+1)){
            dist[now-d]= dist[now]+1;
            q.push(now-d);
        }
    }
    if(dist[g]!=-1){
        printf("%d\n",dist[g]);
    }else {
        printf("use the stairs\n");
    }
    return 0;
}