#include <cstdio>
using namespace std;
int main(){
    int tc;
    scanf("%d", &tc);
    for(int t=1;t<=tc;t++){
        int k;
        long int a=1,b=0,tmp=0;
        scanf("%d", &k);
        for(int i=0;i<k;i++){
            if (i==0){
                a=2;
                b=1;
            }else {
                tmp=a;
                a=tmp+b;
                b=tmp;
            }
        }
        printf("#%d %ld %ld\n",t,a,b);
    }
    return 0;
}