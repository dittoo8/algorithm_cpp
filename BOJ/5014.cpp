#include <cstdio>
#include <cstring>
using namespace std;
int visit[1000001];
int f,g,s,u,d, cnt;
void dfs(int now,int cnt){
    if (now <1 || now > f) return;
    if (now == g){
        visit[now]=cnt;
        return;
    }
    if (visit[now]== -1){
        visit[now] = cnt;
        dfs(now+u, cnt+1);
        dfs(now-d, cnt+1);
    }
}
int main(){
    scanf("%d %d %d %d %d", &f, &s, &g, &u, &d);
    //전체 층 수, 현재 층, 목표 층, 위로 u층, 아래로 d층
    memset(visit,-1,sizeof(visit));
    dfs(s,0);
    if (visit[g]!=-1){
        printf("%d\n", visit[g]);
    }else {
        printf("use the stairs\n");
    }
    return 0;
}