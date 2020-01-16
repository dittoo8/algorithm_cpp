#include <cstdio>
#include <algorithm>
using namespace std;
int n;
int d[1002][3];
int c[1002][3];
int dp(){
    d[1][0] = c[1][0];
    d[1][1] = c[1][1];
    d[1][2] = c[1][2];

    for(int i=1;i<=n;i++){
        d[i][0] = min(d[i-1][1], d[i-1][2]) + c[i][0];
        d[i][1] = min(d[i-1][0], d[i-1][2]) + c[i][1];
        d[i][2] = min(d[i-1][0], d[i-1][1]) + c[i][2];
    }
    return min(min(d[n][0],d[n][1]),d[n][2]);
}
int main(){
    scanf("%d", &n);

    for(int i=1;i<=n;i++){
        scanf("%d %d %d", &c[i][0], &c[i][1], &c[i][2]);
    }
    printf("%d", dp());
    return 0;

}