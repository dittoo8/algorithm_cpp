#include <cstdio>
using namespace std;
int main(){
    int g;
    scanf("%d", &g);
    long long hi=1;
    long long lo=1;
    bool ck = false;
    while(true){
        long long now = hi*hi-lo*lo;
        if(hi-lo==1 && now>g) break;
        if (now >=g) lo++;
        else hi++;
        if(now == g){
            printf("%lld\n",hi);
            ck=true;
        }
    }
    if(!ck) printf("-1\n");
    return 0;
}