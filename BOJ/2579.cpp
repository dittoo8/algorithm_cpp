#include <cstdio>
#include <algorithm>
using namespace std;
int n;
int s[302];
int d[302];
int dp(int n){
    if (n==0) return d[0] = 0;
    if (n==1) return d[1] = s[1];
    if (n==2) return d[2] = s[1] + s[2];
    if(d[n]!=0) return d[n];
    d[n] = s[n] + max(dp(n-3)+s[n-1], dp(n-2));
    return d[n];
    
}
int main(){
    scanf("%d", &n);
    for(int i=1;i<=n;i++) {
        scanf("%d", &s[i]);
    }
    printf("%d", dp(n));

}