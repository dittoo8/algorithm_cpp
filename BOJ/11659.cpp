#include <cstdio>
using namespace std;
int main(){
    int aSum[100002];
    int n,m;
    scanf("%d %d", &n, &m);
    for(int i=1;i<=n;i++){
        int temp;
        scanf("%d", &temp);
        aSum[i]= aSum[i-1]+temp;
    }
    while(m--){
        int s, e;
        scanf("%d %d", &s, &e);
        printf("%d\n", aSum[e]-aSum[s-1]);
    }
    return 0;
}