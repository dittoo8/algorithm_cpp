#include <cstdio>
#include <cstdlib>
using namespace std;
int dist[1002];
int a[1002];
int main(){
    int n,m;
    scanf("%d %d", &n ,&m);
    for(int i=0;i<n;i++){
        int temp;
        scanf("%d", &temp);
        a[i]=temp;
        dist[i] = abs(a[i]-a[i-1]);
    }
    while(m--){
        int tempA, tempB;
        scanf("%d %d", &tempA, &tempB);
        int res = 0;
        for(int i=tempA;i<tempB;i++){
            res+=dist[i];
        }
        printf("%d\n", res);
    }

    return 0;
}