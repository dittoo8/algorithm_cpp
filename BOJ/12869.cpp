#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int INF = 987654321;
int cache[61][61][61];
int dp(int a, int b, int c){
    if(a<0) return dp(0,b,c);
    if(b<0) return dp(a,0,c);
    if(c<0) return dp(a,b,0);
    if(a==0 && b==0 && c==0) return 0;
    int& ret = cache[a][b][c];
    if(ret!=-1) return ret;
    ret=INF;
    ret = min(ret, dp(a - 9, b - 3, c - 1) + 1);
	ret = min(ret, dp(a - 9, b - 1, c - 3) + 1);

	ret = min(ret, dp(a - 1, b - 3, c - 9) + 1);
	ret = min(ret, dp(a - 1, b - 9, c - 3) + 1);

	ret = min(ret, dp(a - 3, b - 1, c - 9) + 1);
	ret = min(ret, dp(a - 3, b - 9, c - 1) + 1);

	return ret;
}
int main(){
    int n;
    scanf("%d", &n);
    int cand[3]= {0,0,0};
    int ans;
    for(int i=0;i<n;i++){
        scanf("%d", &cand[i]);
    }
    memset(cache,-1,sizeof(cache));
    ans = dp(cand[0],cand[1],cand[2]);
    printf("%d\n",ans);
    return 0;
}