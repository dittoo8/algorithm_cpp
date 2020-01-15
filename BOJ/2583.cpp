#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
int cnt = 0;
int n,m,k;
vector<int> res;
pair<int, int> b[103];
int a[103][103];
const int dx[] = {-1, 1, 0,0}, dy[] = {0,0,-1,1};
int dfs(int x, int y){
    int cnt = 1;
    a[x][y] = true;
    for(int i=0;i<4;i++){
        int nx = x+dx[i], ny = y+dy[i];
        if(nx<0 || nx>=m || ny<0 ||ny>=n) continue;
        if(!a[nx][ny]) {
            cnt+=dfs(nx,ny);
        }
    }
    return cnt;
}
int main(){
    scanf("%d %d %d", &m, &n, &k);

    while (k--) {
        int e, b, c, d;
        scanf("%d %d %d %d", &e, &b, &c, &d);
        for (int i = b; i < d; i++)
            for (int j = e; j < c; j++)
                a[i][j] = 1;
    }

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cnt = 0;
            if(!a[i][j]) {
                res.push_back(dfs(i,j));
                
            }
        }
    }
    sort(res.begin(),res.end());
    printf("%d\n", (int)res.size());
    for(int i=0;i<res.size();i++){
        printf("%d ", res[i]);

    }
    return 0;
}