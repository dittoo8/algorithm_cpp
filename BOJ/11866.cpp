#include <cstdio>
#include <queue>
using namespace std;
int main(){
    int ans[1001];
    int n,k,t=1,idx=0;
    scanf("%d %d", &n, &k);
    queue<int> q;
    for(int i=1;i<=n;i++){
        q.push(i);
    }
    while(!q.empty()){
        if (t%k ==0){
            ans[idx]=q.front();
            q.pop();
            idx++;
        }else {
            q.push(q.front());
            q.pop();
        }
        t++;
    }
    printf("<");
    for(int i=0;i<n-1;i++){
        printf("%d, ",ans[i]);
    }
    printf("%d>",ans[n-1]);
    return 0;
}