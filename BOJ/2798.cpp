#include <cstdio>
using namespace std;
int a[101];
int main(){
    int n,m,ans=0;
    scanf("%d %d", &n, &m);
    for(int i=0;i<n;i++){
        scanf("%d", &a[i]);
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k = j+1;k<n;k++){
                int now = a[i]+a[j]+a[k];
                if (now<=m && now > ans){
                    ans = now;
                }
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}