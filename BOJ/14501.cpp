#include <cstdio>
using namespace std;
int n;
int dp[50];
int main(){
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        int t,p;
        scanf("%d %d", &t, &p);
        //t : 상담 소요 일수, p : t일후 받는 금액
        if (dp[i] > dp[i+1]) dp[i+1] = dp[i];
        // 내일까지 번돈이 오늘까지 번돈보다 적으면, 오늘까지 번돈을 내일 넣음.
        if(dp[i+t]< dp[i] + p) dp[i+t] = dp[i] + p;
    }
    printf("%d", dp[n]);
    return 0;
}