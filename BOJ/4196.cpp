#include <iostream>
#include <vector>
#include <stack>
#define MAX 100002

using namespace std;
int n,m;
int idx, d[MAX];
bool finished[MAX];
vector<int> a[MAX];
vector<vector<int> > SCC;
stack<int> s;
int group[MAX];
bool inDegree[MAX];
int dfs(int x){
    d[x] = ++idx;
    s.push(x);
    int res = d[x];
    for(int i=0;i<a[x].size();i++){
        int y = a[x][i];
        if(d[y]==0) res = min(res,dfs(y));
        else if (!finished[y]) res = min(res,d[y]);
    }
    if(res==d[x]){
        vector<int> scc;
        while(1){
            int t= s.top();
            s.pop();
            scc.push_back(t);
            group[t] = SCC.size() + 1;
            finished[t] = 1;
            if(t == x) break;
        }
        SCC.push_back(scc);
    }
    return res;

}
int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        SCC.clear();
        fill(d,d+MAX, 0);
        fill(finished,finished+MAX, 0);
        fill(inDegree,inDegree+MAX, 0);
        scanf("%d %d", &n, &m);
        for(int i=1;i<=n;i++){
            a[i].clear();
        }
        for(int i=0;i<m;i++){
            int x,y;
            scanf("%d %d", &x, &y);
            a[x].push_back(y);
        }
        for(int i=1;i<=n;i++){
            if(d[i]==0) dfs(i);
        }
        for(int i=1;i<=n;i++){
            for(int j=0;j<a[i].size();j++){
                int y = a[i][j];
                
                if(group[i]!=group[y]){
                    inDegree[group[y]] = true;
                    //진입차수가 있다고 표시
                } 
            }
        }
        int res = 0;
        for(int i=1;i<=SCC.size();i++){
            if(!inDegree[i]) res++;
        }
        printf("%d\n",res);
    }
    return 0;
}