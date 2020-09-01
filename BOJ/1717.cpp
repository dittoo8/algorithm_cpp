#include <iostream>
#define MAX 1000001
using namespace std;
int parent[MAX];
int find(int x){
    if (x == parent[x]){
        return x;
    }else {
        int y = find(parent[x]);
        parent[x] = y;
        return y;
    }
}
void union_P(int a, int b){
    a = find(a);
    b = find(b);
    if (a < b){
        parent[b] = a;
    } else parent[a] = b;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i=0;i<=n;i++){
        parent[i] = i;
    }
    int u,a,b;
    for(int i=0;i<m;i++){
        cin >> u >> a >> b;
        if (u == 0){
            union_P(a,b);
        }else {
            a = find(a);
            b = find(b);
            if (a == b){
                cout << "YES" << '\n';
            }else cout << "NO" << '\n';
        }
    }
    return 0;
}