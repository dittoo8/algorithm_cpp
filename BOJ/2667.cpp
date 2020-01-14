#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int dx[] = {-1,0,0,1}, dy[] = {0,-1,1,0};
vector<int> res;
int n;
int map[26][26];
bool check[26][26];
int dfs(int x, int y) {
    int temp = 0;
    for(int i=0;i<4;i++){
        int nx = x+ dx[i], ny = y + dy[i];
        if (nx <0 || nx >= n || ny <0 || ny >= n) continue;
        if(map[nx][ny]==1 && !check[nx][ny]) {
            check[nx][ny] = true;
            temp++;
            temp += dfs(nx,ny);
        }
    }
    return temp;
}
int main(){
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%1d", &map[i][j]);
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(map[i][j] == 1 && !check[i][j]){
                check[i][j] = true;
                res.push_back(dfs(i,j)+1);
            }
        }
    }
    printf("%d\n", (int)res.size());
    sort(res.begin(), res.end());
    for(int i=0;i<res.size();i++){
        printf("%d\n",res[i]);
    }

    return 0;
}
