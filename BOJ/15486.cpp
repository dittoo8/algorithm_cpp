
#include <cstdio>
#include <algorithm>
#define MAX 1500010
using namespace std;
int n, res;
int dp[MAX], a[MAX][2];
int main(){
    scanf("%d", &n);
    for(int i=1;i<=n;i++){
        scanf("%d %d", &a[i][0], &a[i][1]);
    }
    int tmpMax =0;
    for(int i=1;i<=n+1;i++){
        tmpMax = max(tmpMax, dp[i]);
        if (i+a[i][0] > n+1) continue;
        dp[i+a[i][0]] = max(tmpMax + a[i][1],dp[i+a[i][0]]);
    }
    res = tmpMax;
    printf("%d\n",res);
    return 0;
}
