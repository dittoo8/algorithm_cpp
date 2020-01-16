#include <cstdio>
#include <queue>
#include <vector>
using namespace std;
int a[102][102];
bool check[102][102];
int res[102][102];
int n;
void dfs(int num, int x, int y){
    res[num][y] = 1;
    check[num][y] = true;
    for(int i=0;i<n;i++){
        if(a[y][i] == 1 && !check[num][i]) {
            dfs(num,y,i);
        }
    }
}
int main(){
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d", &a[i][j]);
        }
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(a[i][j]==1) {
                
                dfs(i,i,j);
            }
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%d ", res[i][j]);
        }
        printf("\n");
    }
    return 0;
}