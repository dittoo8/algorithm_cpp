#include <cstdio>
#include <vector>
#include <queue>
#define MAX 32001
using namespace std;
int n, degree[MAX], result[MAX];
vector<int> a[MAX];
void topologySort(){
    queue<int> q;
    for(int i=1;i<=n;i++){
        if(degree[i]==0){
            //진입차수가 0 인, 시작점 가능한 노드 큐에 추가
            q.push(i);
        }
    }
    for(int i=1;i<=n;i++){
        int x = q.front();
        q.pop();
        result[i] = x;
        for(int j=0;j<a[x].size();j++){
            int y = a[x][j];
            if(--degree[y] == 0) q.push(y);
        }
    }
    for(int i=1;i<=n;i++)
    printf("%d ", result[i]);

}
int main(){
    int m;
    scanf("%d %d", &n, &m);
    for(int i=0;i<m;i++){
        int x, y;
        scanf("%d %d", &x, &y);
        a[x].push_back(y);
        degree[y]++;
    }
    topologySort();
    return 0;
}