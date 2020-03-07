#include <cstdio>
using namespace std;
int n,m;
bool ck[10];
int a[10];
void dfs(int idx,int cur){
    if(idx == m){
        for(int i=0;i<m;i++){
            printf("%d ",a[i]);
        }
        printf("\n");
        return;
    }else {
        for(int i=cur;i<=n;i++){
            if(!ck[i]){
                a[idx]= i;
                ck[i]=true;
                dfs(idx+1,i+1);
                ck[i]=false;
            }
        }
    }
}
int main(){
    scanf("%d %d", &n, &m);
    dfs(0,1);
    return 0;
}