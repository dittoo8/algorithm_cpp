#include <cstdio>
#include <queue>
using namespace std;
int n,k;
int main(){
    scanf("%d %d",&n, &k);
    queue<int> q;
    printf("<");
    for(int i=1;i<=n;i++) q.push(i);
    for(int i=0;i<n-1;i++){
        for(int j=0;j<k-1;j++){
            q.push(q.front());
            q.pop();
        }
        printf("%d, ", q.front());
        q.pop();
    }
    printf("%d", q.front());
    printf(">");
    return 0;
}