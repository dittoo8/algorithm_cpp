#include <cstdio>
#include <algorithm>
using namespace std;
int n;
int d[10002][3];
int p[10002];
int max3(int a, int b, int c){
    int res;
    res  = max(a, b);
    return res = max(res,c);
}
int main(){
    scanf("%d", &n);
    for(int i=1;i<=n;i++){
        scanf("%d", &p[i]);
    }
    d[1][0] = 0;
    d[1][1] = p[1];
    for(int i=2;i<=n;i++){
        d[i][0] = max3(d[i-1][0],d[i-1][1],d[i-1][2]);
        //이번에 안마실 때
        d[i][1] = d[i-1][0]+p[i];
        //이번에 연속 1번째로 마실때, 이전에 안마셨을때
        d[i][2] = d[i-1][1]+p[i];
        //이번에 연속 2번째로 마실때, 이전에 연속 1번째로 마셨을때
    }

    printf("%d", max3(d[n][0],d[n][1],d[n][2]));
    return 0;
}