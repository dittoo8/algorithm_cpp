#include <cstdio>
#include <cmath>
using namespace std;
long long num,n;
int main(){
    scanf("%lld", &num);
    n=sqrt(2.0*num);
    while(n*(n+1)<=num*2){
        n++;
    }
    printf("%lld\n",n-1);
    return 0;
}