/*
준규가 가지고 있는 동전은 총 N종류이고, 각각의 동전을 매우 많이 가지고 있다.

동전을 적절히 사용해서 그 가치의 합을 K로 만들려고 한다. 이때 필요한 동전 개수의 최솟값을 구하는 프로그램을 작성하시오.
*/
#include <cstdio>
using namespace std;
int main(){
    int n,k;
    scanf("%d %d",&n, &k);
    int coin[n];
    for(int i=n-1;i>=0;i--){
        scanf("%d",&coin[i]);
    }
    int cnt = 0;
    while(k == 0){
    }
    int temp;
    for(int i=0;i<n;i++){
        if(k/coin[i]>0) {
            cnt+=k/coin[i];
            k %= coin[i];
        }
    }
    printf("%d", cnt);
}