#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAX 501
#define MAXR 2100000000
using namespace std;
int n;
int d[MAX][MAX], a[MAX];
int sum[MAX];
int dp(int i,int j){
    if(i==j) return 0;
    int tmp = MAXR;
    for(int k=0;k<j-i;k++){
        tmp = min(tmp, d[i][i+k]+d[i+k+1][j]+sum[j]-sum[i-1]);
    }
    return tmp;
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        memset(d,0,sizeof(d));
        memset(a,0,sizeof(a));
        memset(sum,0,sizeof(sum));
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d", &a[i]);
            sum[i] = sum[i-1]+a[i];
        }
        for(int i=0;i<=n;i++){
            for(int j=1;i+j<=n;j++){
                d[j][i+j] = dp(j,i+j);
            }
        }
        printf("%d\n",d[1][n]);
    }
    return 0;
}