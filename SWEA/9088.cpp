#include <cstdio>
#include <algorithm>
using namespace std;
int main(){
    int a[1001];
    int tc;
    scanf("%d",&tc);
    for(int t=1;t<=tc;t++){
        int n,k,res=0;
        scanf("%d %d", &n, &k);
        for(int i=0;i<n;i++){
            scanf("%d", &a[i]);
        }
        sort(a,a+n);
        int l=0,r=0;
        while(r<n && l<=r){
            if (a[r]-a[l]>k) l++;
            else {
                res = max(res,r-l+1);
                r+=1;
            }
        }
        printf("#%d %d\n",t, res);
    }
    return 0;
}