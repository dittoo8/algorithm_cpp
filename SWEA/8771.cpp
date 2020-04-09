#include <cstdio>
using namespace std;
int main(){
    int tc;
    scanf("%d", &tc);
    for(int t=1;t<=tc;t++){
        long long n,a,b;
        scanf("%lld %lld %lld", &n, &a, &b);
        if (a==b){
            printf("#%d 1\n",t);
        } else if (a>b || n ==1){
            printf("#%d 0\n",t);
        }else if (n==2){
            printf("#%d 2\n",t);
        }else {
            long long res = (n-2)*(b-a)+1;
            printf("#%d %lld\n",t,res);
        }
    }
    return 0;
}