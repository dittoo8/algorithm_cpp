#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 502
using namespace std;
int n;
vector<int> a[MAX];
int degree[MAX],result[MAX], t[MAX];
void topologySort(){
    queue<int> q;
    for(int i=1;i<=n;i++){
        if(degree[i]==0) {
            result[i] = t[i];
            q.push(i);
        }
    }

    for(int i=1;i<=n;i++){
        int x = q.front();
        q.pop();
        for(int j=0;j<a[x].size();j++){
            int y = a[x][j];
            result[y] = max(result[y], result[x]+ t[y]);
            if(--degree[y]==0) q.push(y);
        }
    }
    for(int i=1;i<=n;i++){
        printf("%d\n", result[i]);
    }
}
int main(){
    scanf("%d", &n);
    for(int i=1;i<=n;i++){
        scanf("%d", &t[i]);
        while(1){
            int x;
            scanf("%d", &x);
            if (x == -1) break;
            degree[i]++;
            a[x].push_back(i);
        }
    }
    topologySort();
    return 0;

}