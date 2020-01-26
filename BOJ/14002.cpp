#include <cstdio>
using namespace std;
int a[1001];
int d[1001];
// 길이저장
int v[1001] = {-1,};
// 앞 idx 저장
int n;
int max = 0;
void popnum(int p){
    if (p==0) return;
    popnum(v[p]);
    //재귀로 제일 첫번째 숫자부터 출력

    printf("%d ", a[p]);
}
int main(){
    scanf("%d", &n);
    for(int i=1;i<=n;i++){
        scanf("%d", &a[i]);
    }
    for(int i=1;i<=n;i++){
        d[i] = 1;
        for(int j=1;j<i;j++){
            if(a[i] > a[j] && d[i] < d[j]+1){
                d[i] = d[j] + 1;
                v[i] = j;
            }
        }
    }
    int p=0;
    for(int i=1;i<=n;i++){
        if (max < d[i]){
            max = d[i];
            p = i;
        }
    }
    printf("%d\n",max);
    //최대길이
    popnum(p);
    return 0;
}