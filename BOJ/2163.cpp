#include <cstdio>
#include <cstring>
using namespace std;
int n,m,ans;
int cache[301][301];
int dp(int x, int y){
    int& ret = cache[x][y];
    if(ret!=-1) return ret;
    if(x==0 || y==0 || (x==1 && y==1)) return 0;
    ans++;
    return ret = dp(x-1,y)+dp(x,y-1)+1;
}
int main(){
    scanf("%d %d", &n, &m);
    memset(cache,-1,sizeof(cache));
    dp(n,m);
    printf("%d\n",ans);
    return 0;
}