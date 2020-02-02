#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#define MAX 100002
using namespace std;
int d[MAX],idx;
vector<int> a[MAX];
bool finished[MAX];
bool inDegree[MAX];
vector<vector<int> > SCC;
vector<int> result;
int group[MAX];
stack<int> st;
int dfs(int x){
    d[x] = ++idx;
    st.push(x);
    
    int parent = d[x];
    for(int i=0;i<a[x].size();i++){
        int y = a[x][i];
        if(d[y]==0) parent = min(parent,dfs(y));
        else if (!finished[y]) parent = min(parent,d[y]);
    }
    if(parent == d[x]){
        vector<int> scc;
        while(1){
            int t = st.top();
            st.pop();
            scc.push_back(t);
            group[t] = SCC.size() + 1;
            finished[t] = true;
            if(t==x) break;
        }
        SCC.push_back(scc);
    }
    return parent;

}
int main(){
    int t;
    cin >> t;
    while(t--){
        int n,m;
        fill(d, d+MAX, 0);
        fill(finished, finished+MAX, 0);
        fill(inDegree, inDegree+MAX, false);
        SCC.clear();
        result.clear();
        cin >> n>>m;
        for(int i=1;i<=n;i++){
            a[i].clear();
        }
        for(int i=0;i<m;i++){
            int x, y;
            cin >> x >> y;
            a[x+1].push_back(y+1);
        }
        for(int i=1;i<=n;i++){
            if(d[i]==0) dfs(i);
        }
        for(int i=1;i<=n;i++){
            for(int j=0;j<a[i].size();j++){
                int y = a[i][j];
                if(group[i]!=group[y]) {
                    inDegree[group[y]] = true;
                }
            }
        }
        int cnt = 0;
        for(int i = 0;i<SCC.size();i++){
            if(!inDegree[i+1]){
                cnt++;
                for(int j=0;j<SCC[i].size();j++){
                    result.push_back(SCC[i][j]-1);
                }
            }
        }
        sort(result.begin(),result.end());
        if(cnt!=1){
            printf("Confused\n\n");
        } else {
            for(int i=0;i<result.size();i++){
                printf("%d\n",result[i]);
            }
            printf("\n");
        }

    }
    return 0;
}