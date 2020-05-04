#include <cstdio>
#include <algorithm>
using namespace std;
int main(){
    for(int t=1;t<=10;t++){
        int res;
        int d;
        int a[100];
        scanf("%d", &d);
        for(int i=0;i<100;i++){
            scanf("%d", &a[i]);
        }
        sort(a,a+100);
        while(d--){
            a[0]++;
            a[99]--;
            sort(a,a+100);
        }
        printf("#%d %d\n",t, a[99]-a[0]);
    }
    return 0;
}