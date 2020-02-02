#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#define MAX 10002

using namespace std;
int idx, d[MAX];
bool finished[MAX];
vector<int> a[MAX];
vector<vector<int> > SCC;
stack<int> s;
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
            finished[t] = 1;
            if(t == x) break;
        }
        sort(scc.begin(),scc.end());
        SCC.push_back(scc);
    }
    return res;

}
int main(){
    int v,e;
    scanf("%d %d", &v, &e);
    for(int i=0;i<e;i++){
        int x,y;
        scanf("%d %d", &x, &y);
        a[x].push_back(y);
    }
    for(int i=1;i<=v;i++){
        if(d[i]==0) dfs(i);
    }
    printf("%d\n",(int)SCC.size());
    //size 출력 오류.. BOJ에선 통과
    sort(SCC.begin(),SCC.end());
    for(int i=0;i<SCC.size();i++){
        for(int j=0;j<SCC[i].size();j++){
            printf("%d ", SCC[i][j]);
        }
        printf("-1\n");
    }
    return 0;
}