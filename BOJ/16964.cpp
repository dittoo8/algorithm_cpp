#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int n;
vector<int> order,d;
vector<int> a[100001],dfs_order;
bool check[100001];
void dfs(int x){
    check[x]=true;
    dfs_order.push_back(x);
    for(int i=0;i<a[x].size();i++){
        if (!check[a[x][i]]){
            dfs(a[x][i]);
        }
    }
}
bool cmp(int u, int v){
    return order[u] < order[v];
}
int main(){
    scanf("%d", &n);
    order.resize(n+1);
    d.resize(n+1);
    order[0]=0;
    d[0]=0;
    dfs_order.push_back(0);
    int ta, tb;
    for(int i=0;i<n-1;i++){
        scanf("%d %d", &ta, &tb);
        a[ta].push_back(tb);
        a[tb].push_back(ta);
    }
    for(int i=1;i<=n;i++){
        scanf("%d", &d[i]);
        order[d[i]]=i;
    }
    for(int i=1;i<=n;i++){
        sort(a[i].begin(),a[i].end(),cmp);
    }
    dfs(1);
    if(d==dfs_order){
        printf("1\n");
    }else printf("0\n");
    return 0;
}