#include <cstdio>
#include <algorithm>
#include <vector>
#include <stack>
#include <cstring>
using namespace std;
const int MAX_V = 20001;
vector<vector<int> > adj;
int sccId[MAX_V],discovered[MAX_V],sccCnt,discCnt;
stack<int> st;
int makeSCC(int x){
    st.push(x);
    discovered[x]=++discCnt;
    int parent = discovered[x];
    for(int i=0;i<adj[x].size();i++){
        int next = adj[x][i];
        if(discovered[next]==-1) parent=min(parent,makeSCC(next));
        else if (sccId[next]==-1) parent=min(parent,discovered[next]);
    }
    if(parent == discovered[x]){
        while(true){
            int t = st.top();
            st.pop();
            sccId[t]=sccCnt;
            if(t==x) break;
        }
        sccCnt++;
    }
    return parent;
}
int main(){
    int n,m,t,s1,s2,i,ans,ind[MAX_V], outd[MAX_V],inc,outc;
    scanf("%d", &t);
    while(t--){
        scanf("%d %d", &n, &m);
        while(!st.empty()) st.pop();
        adj.clear(); adj.resize(n);
        ans = sccCnt = discCnt = 0;
        memset(sccId,-1,sizeof(sccId));
        memset(discovered,-1,sizeof(discovered));
        while(m--){
            scanf("%d %d", &s1, &s2);
            s1--, s2--;
            adj[s1].push_back(s2);
        }
        for(int i=0;i<n;i++){
            if(discovered[i]==-1) makeSCC(i);
        }
        memset(ind,0,sizeof(ind));
        memset(outd,0,sizeof(outd));
        for(int i=0;i<n;i++){
            for(int j=0;j<adj[i].size();j++){
                if(sccId[i]!=sccId[adj[i][j]]){
                    outd[sccId[i]]++;
                    ind[sccId[adj[i][j]]]++;
                }
            }
        }
        inc = outc =0;
        for(int i=0;i<sccCnt;i++){
            if(!ind[i]) inc++;
            if(!outd[i]) outc++;
        }
        printf("%d\n",sccCnt==1?0:max(inc,outc));
    }
    return 0;
}