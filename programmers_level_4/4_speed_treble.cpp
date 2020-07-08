#include <iostream>
#include <cmath>
using namespace std;
// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int res;
void dfs(int now, int cnt){
    if(now < 1 || 2*log(now)/log(3)<cnt) return;
    if(now == 3){
        if(cnt ==2) res++;
        return;
    }
    if(now%3 ==0 && cnt>=2){
        dfs(now/3, cnt-2);
    }
    dfs(now-1,cnt+1);
}
int solution(int n) {
    res = 0;
    dfs(n-2,2);
    return res;
}
int main(){
    cout << solution(41) << endl;
    return 0;
}