#include <cstdio>
using namespace std;
int main(){
    int tc;
    scanf("%d",&tc);
    while(tc--){
        int m,n,x,y;
        scanf("%d %d %d %d", &m, &n, &x, &y);
        bool flag = true;
        for(int i=0;i<m;i++){
            if ((n*i+y-x)%m==0){
                printf("%d\n",i*n+y);
                flag=false;
                break;
            }
        }
        if (flag) printf("-1\n");
    }
    return 0;
}