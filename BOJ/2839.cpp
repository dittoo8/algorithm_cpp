#include <cstdio>
using namespace std;
int main(){
    int n;
    scanf("%d", &n);
    int cnt_5 = n/5;
    n = n - cnt_5*5;
    for(int i= cnt_5; i>=0;i--){
        if (n%3 ==0 ){
            printf("%d\n",i+n/3);
            return 0;
        }
        n+=5;
    }
    printf("-1\n");
    return 0;
}