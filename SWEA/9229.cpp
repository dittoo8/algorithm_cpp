#include <cstdio>
using namespace std;
int main(){
    int tc;
    int a[1001];
    scanf("%d", &tc);
    for(int i=1;i<=tc;i++){
        int res=-1,n,m;
        scanf("%d %d", &n, &m);
        for(int j=0;j<n;j++){
            scanf("%d",&a[j]);
        }
        for(int j=0;j<n;j++){
            for(int k=j+1;k<n;k++){
                int now =a[j]+a[k];
                if(now <=m && res < now){
                    res = now;
                }
            }
        }
        printf("#%d %d\n",i,res);
    }
    return 0;
}