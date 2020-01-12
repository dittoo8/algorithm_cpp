#include <cstdio>
using namespace std;
long long d[92] = {0,1,1};
int main(){
    long long n;
    scanf("%lld", &n);
    for(int i=3;i<=n;i++){
        d[i] = d[i-1] + d[i-2];
    }
    printf("%lld", d[n]);
}