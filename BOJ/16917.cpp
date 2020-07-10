#include <cstdio>
#include <algorithm>
using namespace std;
long long a,b,c,x,y,ans;
int main(){
    scanf("%lld %lld %lld %lld %lld", &a, &b, &c, &x, &y);
    ans = a*x+b*y;
    if(x > y){
        ans = min(ans, c*2*x);
        ans = min(ans, c*y*2 + (x-y)*a);
    }else {
        ans = min(ans, c*2*y);
        ans = min(ans, c*x*2 + (y-x)*b);
    }
    printf("%lld\n",ans);
    return 0;
}