#include <iostream>
#include <vector>
#include <queue>
#define MAX 1001
using namespace std;
int n, inDegree[MAX];
vector<int> a[MAX];
int result[MAX];
void topology_Sort(){
    queue<int> q;
    for(int i=1;i<=n;i++){
        if (inDegree[i] ==0) q.push(i);
    }
    for(int i=0;i<n;i++){
        if (q.empty()){
            cout << 0 << '\n';
            return;
        }
        int x = q.front();
        q.pop();
        for(int k=0;k<a[x].size();k++){
            int next = a[x][k];
            if (--inDegree[next]==0){
                q.push(next);
            }
        }
        result[i] = x;
    }
    for(int i=0;i<n;i++){
        cout << result[i] << '\n';
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int m;
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int k,prev,curr;
        cin >> k;
        if (k==0) continue;
        cin >> prev;
        for(int j=1;j<k;j++){
            cin >> curr;
            a[prev].push_back(curr);
            inDegree[curr]++;
            prev = curr;
        }
    }
    topology_Sort();
    
    return 0;
}