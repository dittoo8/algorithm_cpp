#include <cstdio>
#include <algorithm>
int a[100002];
using namespace std;
int main(){
    int n,m;
    scanf("%d %d", &n, &m);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    sort(a,a+n);
    int j=0;
    int res=2e9;
    for(int i=0;i<n &&j<n;){
        if(a[i]-a[j]>=m){
            res=min(res,a[i]-a[j]);
            j++;
        }else i++;
    }
    printf("%d",res);
    return 0;
}