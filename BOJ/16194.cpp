#include <cstdio>
#include <algorithm>
using namespace std;
int d[1002];
int n;
int c[1002];
int dp(int x){
    if(x==1) return c[1];
    if(d[x]!=0) return d[x];
    d[x] = c[x];
    for(int i=1;i<=x;i++){
        d[x] = min(dp(x-i)+c[i],d[x]);
    }
    return d[x];
}
int main(){
    scanf("%d", &n);
    for(int i=1;i<=n;i++){
        scanf("%d", &c[i]);
    }
    printf("%d", dp(n));
    return 0;

}