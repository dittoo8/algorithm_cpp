#include <cstdio>
using namespace std;
int main(){
    int n,m, a[10001];
    scanf("%d %d", &n, &m);
    for(int i=0;i<n;i++){
        scanf("%d", &a[i]);
    }
    int res = 0;
    int sum = 0;
    int l = 0;
    int h=0;
    while(1){
        if(sum>=m) sum-=a[l++];
        else if (h ==n) break;
        else sum+=a[h++];
        if(sum==m) res++;
    }
    printf("%d\n",res);
    return 0;
}
