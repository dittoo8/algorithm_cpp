#include <cstdio>
#include <vector>
#define MAX 10005
using namespace std;
int V,E;
vector<int> graph[MAX];
int cnt;
int order[MAX];
int ans_cnt;
bool cutVertex[MAX];
int dfs(int cur, bool is_Root){
    order[cur] = ++cnt;
    int ret = order[cur]; //현재 노드의 방문순서
    int child = 0;
    for(int i=0;i<graph[cur].size();i++){
        int next = graph[cur][i];
        if(!order[next]){ //다음 정점이 아직 방문하지 않은 노드라면
            child++;
            int low = dfs(next,false);
            if(!is_Root && order[cur] <= low){
                cutVertex[cur] = true;
            }
            ret = min(ret,low);
        }else ret = min(ret, order[next]);
    }
    if (is_Root) cutVertex[cur] = child>=2;
    return ret;
}
int main(){
    scanf("%d %d", &V, &E);
    int u,v;
    for(int i=0;i<E;i++){
        scanf("%d %d", &u, &v);
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    for(int i=1;i<=V;i++){
        if(!order[i]) dfs(i,true);
    }
    for(int i=1;i<=V;i++){
        if (cutVertex[i]) ans_cnt++;
    }
    printf("%d\n", ans_cnt);
    for(int i=1;i<=V;i++){
        if (cutVertex[i]) printf("%d ", i);
    }
    return 0;
}