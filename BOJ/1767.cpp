#include <cstdio>
#include <cstring>
#define MOD 1000001
using namespace std;
long long d[101][101][101];
long long go(int n, int m, int k){
    //룩을 k개 다 놓았을 때 OK
    if (k==0) return 1;
    if ( n<= 0 || m <=0 || k <0) {
        //남은 행 또는 열, 룩의 갯수가 없는 경우
        return 0;
    }
    if (d[n][m][k]!= -1) return d[n][m][k];
    d[n][m][k] = go(n-1,m,k) +
        go(n-1,m-1,k-1)*m +
        go(n-1,m-2,k-2)*m*(m-1)/2 +
        go(n-2,m-1,k-2)*m*(n-1);
    d[n][m][k]%=MOD;
    return d[n][m][k];
}
int main(){
    int  n,m,k;
    scanf("%d %d %d", &n, &m, &k);
    memset(d,-1,sizeof(d));
    printf("%lld\n",go(n,m,k));
    return 0;
}