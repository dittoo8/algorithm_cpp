#include <cstdio>
using namespace std;
int dp(int n){
    if (n==1) return 1;
    if (n==2) return 2;
    if (n==3) return 4;
    return dp(n-3) + dp(n-2) + dp(n-1);

}
int main(){
    int n;
    int num;
    scanf("%d", &n);
    while(n--){
        scanf("%d", &num);
        printf("%d\n",dp(num));
    }
}