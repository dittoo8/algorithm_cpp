#include <cstdio>
using namespace std;
int n,a[101],res;
long d[101][21];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    d[1][a[1]]++;
    for(int i=2;i<n;i++){
        for(int j=0;j<=20;j++){
            if(d[i-1][j]){
                if(j+a[i]<=20) d[i][j+a[i]]+=d[i-1][j];
                if(j-a[i]>=0) d[i][j-a[i]]+=d[i-1][j];
            }
        }
    }
    printf("%ld\n",d[n-1][a[n]]);
    return 0;
}