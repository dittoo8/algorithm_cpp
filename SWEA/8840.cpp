#include <cstdio>
using namespace std;
int main(){
    int tc;
    scanf("%d", &tc);
    for(int t=1;t<=tc;t++){
        long long l;
        long long res;
        scanf("%lld", &l);
        res = (l-1)/2;
        printf("#%d %lld\n",t,res*res);
    }
    return 0;
}