#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int n;
vector<int> a[100001];
bool check[100001];
int main(){
    scanf("%d", &n);
    for(int i=0;i<n-1;i++){
        int u, v;
        scanf("%d %d", &u, &v);
        a[u].push_back(v);
        a[v].push_back(u);
    }
    vector<int> b(n+1);
    vector<int> order(n+1);
    for(int i=1;i<=n;i++){
        scanf("%d", &b[i]);
        order[b[i]]=i;
    }
    for(int i=1;i<=n;i++){
        sort(a[i].begin(),a[i].end(),[&](const int& u, const int &v){
            return order[u]<order[v];
        });
    }
    vector<int> bfs_order;
    bfs_order.push_back(0);
    queue<int> q;
    q.push(1);
    check[1]= true;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        bfs_order.push_back(node);
        for(int i=0;i<a[node].size();i++){
            int next = a[node][i];
            if(!check[next]){
                q.push(next);
                check[next]= true;
            }
        }
    }
    if (bfs_order==b) printf("1\n");
    else printf("0\n");
    return 0;
}