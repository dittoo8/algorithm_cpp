#include <cstdio>
using namespace std;
int main(){
    int tc;
    scanf("%d", &tc);
    for(int t=1;t<=tc;t++){
        int tcn;
        scanf("%d", &tcn);
        int a[101] = {0,};
        int  max=0;
        int res;
        for(int i=0;i<1000;i++){
            int tmp;
            scanf("%d", &tmp);
            a[tmp]++;
            if (a[tmp]>max) max = a[tmp];
        }
        for(int i=100;i>=0;i--){
            if (a[i]==max) {
                res=i;
                break;
            }
        }
        printf("#%d %d\n",tcn,res);
    }
    return 0;
}