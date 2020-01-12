/*
2×n 직사각형을 2×1과 2×2 타일로 채우는 방법의 수를 구하는 프로그램을 작성하시오.

아래 그림은 2×17 직사각형을 채운 한가지 예이다.
*/
#include <cstdio>
using namespace std;
int d[1001];
int dp(int x) {
    if (x==1) return 1;
    if (x==2) return 3;
    if(d[x]!=0) return d[x];
    return d[x] = (dp(x-1) + 2*dp(x-2))%10007;
}
int main(){
    int x;
    scanf("%d", &x);
    printf("%d",dp(x));
}