#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int INF = 987654321;
int n;
int d[61][61][61];
int dp(int a, int b, int c){
    if (a<0) return dp(0,b,c);
    if (b<0) return dp(a,0,c);
    if (c<0) return dp(a,b,0);
    if (a==0 && b==0 && c==0) return 0;
    if (d[a][b][c]!=-1)  return d[a][b][c];
    int t[3] = {1,3,9};
    int ans = INF;
    do {
        int tmp = dp(a-t[0],b-t[1],c-t[2])+1;
        if (ans > tmp) ans = tmp;
    } while(next_permutation(t,t+3));
    return d[a][b][c] = ans;
}
int main(){
    scanf("%d", &n);
    int scv[3] = {0,0,0};
    for(int i=0;i<n;i++){
        scanf("%d", &scv[i]);
    }
    memset(d,-1,sizeof(d));
    printf("%d\n",dp(scv[0],scv[1],scv[2]));
    return 0;
}