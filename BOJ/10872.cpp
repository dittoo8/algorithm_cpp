#include <cstdio>
using namespace std;
int fac(int x){
    if (x <= 1) return 1;
    return x * fac(x-1);
}
int main(){
    int n;
    scanf("%d", &n);
    printf("%d\n", fac(n));
    return 0;
}