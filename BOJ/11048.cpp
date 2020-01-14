#include <cstdio>
#include <algorithm>
using namespace std;
int n,m;
int map[1002][1002];
int d[1002][1002];
int max3(int a, int b, int c){
    int temp = max(a,b);
    temp = max(temp, c);
    return temp;
}
int main(){

    scanf("%d %d", &n ,&m);

    for(int i=1;i<=n;i++){
        for(int j=1; j<=m;j++){
            scanf("%d", &map[i][j]);
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            //처음에 이렇게 세움
            // d[i][j] = map[i][j] + max3(d[i-1][j-1],d[i][j-1],d[i-1][j]);
            // 이렇게 개선 (최단거리 구하는 문제가 아니기때문.)
            d[i][j] = map[i][j] + max(d[i][j-1],d[i-1][j]);
        }
    }
    printf("%d", d[n][m]);
    return 0;
}