 #include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;
int n,m,v;
bool nums[1002];
vector<int> vec[1002];
void dfs(int x){
    if (nums[x]) return;
    nums[x] = true;
    printf("%d ", x);
    for(int i=0;i<vec[x].size();i++){
        if(nums[vec[x][i]]== 0) {
            dfs(vec[x][i]);
            nums[vec[x][i]] = 1;
        }
        
    }
} 
void bfs(int x) {
    queue<int> q;
    q.push(x);
    nums[x] = true;
    while(!q.empty()){
        int f = q.front();
        q.pop();
        printf("%d ", f);
        for(int i=0;i<vec[f].size();i++){
            int y = vec[f][i];

            if(!nums[y]){
                q.push(y);
                nums[y] = true;
            }
        }
    }
}
int main(){
    scanf("%d %d %d", &n, &m, &v);
    for(int i=1;i<=m;i++){
        int a, b;
        scanf("%d %d", &a, &b);
        vec[a].push_back(b);
        vec[b].push_back(a);
    }
    for(int i=1;i<=n;i++){
        sort(vec[i].begin(), vec[i].end());
    }
    dfs(v);
    printf("\n");
    memset(nums, 0, sizeof(nums));
    bfs(v);

    return 0;
}