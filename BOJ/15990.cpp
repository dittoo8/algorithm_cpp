#include <cstdio>
using namespace std;
int t,n;
const long long mod = 1000000009;
long long d[3][100002];
int main(){
    d[0][1] = d[1][2] = d[0][3] = d[1][3] = d[2][3] = 1;
    for (int i = 4; i <= 100000; i++) {
        d[0][i] = (d[1][i-1]+d[2][i-1])%mod;
        d[1][i] = (d[0][i-2]+d[2][i-2])%mod;
        d[2][i] = (d[0][i-3]+d[1][i-3])%mod;
    }
    for (scanf("%d", &t); t--;) {
        scanf("%d", &n);
        printf("%lld\n", ((long long)d[0][n]+d[1][n]+d[2][n])%mod);
    }
    return 0;
}