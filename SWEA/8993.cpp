#include <cstdio>
#include <queue>
using namespace std;
bool solve (long long n){
    queue<long long> arr;
    while(n>1){
        if (n%2==0){
            n/=2;
        }else {
            arr.push(n);
            if (n == arr.front()) return false;
            n = 3*n+3;
        }
    }
    return true;
}
int main(){
    int tc;
    scanf("%d",&tc);
    long long n;
    for(int t=1;t<=tc;t++){
        scanf("%lld",&n);
        if (solve(n)){
            printf("#%d YES\n",t);
        } else printf("#%d NO\n",t);
    }
    return 0;
}