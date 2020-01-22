#include <string>
#include <vector>
#include <cmath>
#include <cstdio>
using namespace std;
int a[1000002];
int solution(int n) {
    int answer = 0;
    for(int i= 1;i<=n;i++){
        a[i] = i;
    }
    for(int i=2;i<=n;i++){
        if(a[i]==0) continue;
        for(int j=i+i;j<=n;j+=i) {
            a[j] = 0;
        }
    }
    for(int i=2;i<=n;i++){
        if(a[i]!=0) answer++;
    }
    return answer;
}
int main(){
    printf("%d",solution(10));
    return 0;
}