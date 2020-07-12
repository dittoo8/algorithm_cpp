#include <iostream>
#include <vector>
using namespace std;
const int MAX = 1000001;
int N,parent[MAX];
bool visited[MAX];
vector<int> tree[MAX];
void findParent(int idx){
    visited[idx] = true;
    for (int i = 0; i<tree[idx].size(); i++){
        int next = tree[idx][i];
        if (!visited[next]){
            parent[next] = idx;
            findParent(next);
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i<N-1; i++){
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    findParent(1);
    for (int i = 2; i <= N; i++){
        cout << parent[i] << '\n';
    }
    return 0;
}