#include <cstdio>
using namespace std;
int n;
int map[102][102];
long long d[102][102];

int main(){
    scanf("%d", &n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            scanf("%d", &map[i][j]);
        }
    }
    d[1][1] = 1;
    //현재 칸에 올 수 있는 경우의 수.
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i == n && j == n) {
                break;
            }
            if(d[i][j]>0) {
                if(j+map[i][j] <= n) {
                    d[i][j+map[i][j]] += d[i][j];
                }
                if(i+map[i][j] <= n) {
                    d[i+map[i][j]][j] += d[i][j];
                }
                
            }
        }
    }
    
    
    printf("%lld", d[n][n]);
    
    return 0;
}