/*
2×n 크기의 직사각형을 1×2, 2×1 타일로 채우는 방법의 수를 구하는 프로그램을 작성하시오.

아래 그림은 2×5 크기의 직사각형을 채운 한 가지 방법의 예이다.
*/
#include <cstdio>
using namespace std;
int d[1001];
int dp(int x){
    if (x==1) return 1;
    if (x==2) return 2;
    if (d[x] != 0) return d[x];
    return d[x] = (dp(x-1) + dp(x-2))%10007;
}
int main(){
    int x;
    scanf("%d", &x);
    printf("%d",dp(x));
}