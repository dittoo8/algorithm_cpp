#include <cstdio>
#include <cstring>
#define MOD 1000000007
using namespace std;
int s,a,b,c;
long long cache[51][51][51][51];
long long dp(int s,int a, int b,int c){
    if(s==0){
        if(a==0 && b==0 && c==0) return 1;
        else return 0;
    }
    if (a <0 || b <0 || c <0) return 0;
    long long& ret = cache[s][a][b][c];
    if (ret!=-1) return ret;
    ret = 0;
    for(int i=1;i<8;i++){
        int isA = i & 1 ? 1:0;
        int isB = i & 2 ? 1:0;
        int isC = i & 4 ? 1:0;
        ret+=dp(s-1,a-isA,b-isB,c-isC)%MOD;
        ret%=MOD;
    }
    return ret;
}
int main(){
    scanf("%d %d %d %d",&s, &a, &b, &c);
    memset(cache,-1,sizeof(cache));
    printf("%lld\n",dp(s, a, b, c));
    
    return 0;
}