#include <cstdio>
#include <cstring>
#include <vector>
#define MAX 100002
using namespace std;
int n,cnt;
int a[MAX];
bool check[MAX];
bool par[MAX];
void dfs(int x){
    check[x] = true;
    int next = a[x];
    if (!check[next]){
        //다음노드 방문 안했을 때
        dfs(next);
        
    } else if (!par[next]){
        //다음노드 방문했지만 덜끝났을때
        for(int i=next; i!=x;i=a[i]) cnt++;
        cnt++;
    }
    par[x] = true;

}
int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        memset(a,0,sizeof(a));
        memset(check,false, sizeof(check));
        memset(par,false,sizeof(par));
        cnt = 0;
        scanf("%d", &n);
        for(int i=1;i<=n;i++){
            scanf("%d", &a[i]);
        }
        for(int i=1;i<=n;i++){
            if(!check[i]) dfs(i);
        }
        printf("%d\n", n-cnt);
    }
    return 0;
}