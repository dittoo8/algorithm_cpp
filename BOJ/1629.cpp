/*
자연수 A를 B번 곱한 수를 알고 싶다.
단 구하려는 수가 매우 커질 수 있으므로 이를 C로 나눈 나머지를 구하는 프로그램을 작성하시오.
*/
#include <cstdio>
using namespace std;
typedef unsigned long long UUL;
UUL A, B, C;
UUL power(UUL a, UUL b, UUL c){
    if (b==0) return 1;
    if (b==1) return a%c;

    //빠른 지수승
    UUL temp = power(a,b/2,c);
    if (b%2==1) return (((temp*temp)%c)*a) % c;
    else return (temp*temp)%c;
}
int main(){
    scanf("%lld %lld %lld",&A, &B, &C);
    printf("%lld",power(A, B, C));
    
}