#include <cstdio>
using namespace std;
int main(){
    int tc,res,n,x;
    scanf("%d", &tc);
    for(int t=1;t<=tc;t++){
        scanf("%d %d", &n, &x);
        if (x == 2*n-1 || x == 1){
            res = 0;
        }else res =1;
        printf("#%d %d\n",t,res);
    }
    return 0;
}