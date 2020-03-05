#include <cstdio>
#include <vector>
#include <queue>
#define MAX 10001
using namespace std;
int n,s,e;
int inDegree[MAX], res[MAX], check[MAX];
vector<pair<int, int> > forw[MAX];
vector<pair<int, int> > backw[MAX];
//역추적 하기 위해
void topologySort(){
    queue<int> q;
    q.push(s);
    while(!q.empty()){
        int x = q.front();
        q.pop();
        for(int i=0;i<forw[x].size();i++){
            int cur = forw[x][i].first, dist =forw[x][i].second;
            if(res[cur] <= dist + res[x]){
                res[cur] = dist + res[x];
            }
            if(--inDegree[cur]==0) {
                q.push(cur);
            }
        }
        
    }
    int count =  0;
        q.push(e);
        while(!q.empty()){
            int x = q.front();
            q.pop();
            for(int i=0;i<backw[x].size();i++){
                int cur = backw[x][i].first, dist = backw[x][i].second;
                if(res[x]-res[cur]==dist){
                    count ++;
                    if(!check[cur]){
                        q.push(cur);
                        check[cur] = 1;
                    }
                }
            }
        }
    printf("%d\n%d",res[e],count);
}
int main(){
    int m;
    scanf("%d %d", &n, &m);
    for(int i=0;i<m;i++){
        int a, b, cost;
        scanf("%d %d %d", &a, &b, &cost);
        forw[a].push_back(make_pair(b,cost));
        backw[b].push_back(make_pair(a,cost));
        inDegree[b]++;
    }
    scanf("%d %d", &s, &e);
    topologySort();
    return 0;
}