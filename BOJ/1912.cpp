/*n개의 정수로 이루어진 임의의 수열이 주어진다. 
우리는 이 중 연속된 몇 개의 수를 선택해서 구할 수 있는 합 중 가장 큰 합을 구하려고 한다.
단, 수는 한 개 이상 선택해야 한다.
예를 들어서 10, -4, 3, 1, 5, 6, -35, 12, 21, -1 이라는 수열이 주어졌다고 하자.
여기서 정답은 12+21인 33이 정답이 된다.*/
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int N;
    //답을 저장할 변수 ans
    int ans;
    //N을 입력받음
    scanf("%d", &N);
    // 배열 저장 , 크기를 N으로 초기화
    int area[N];
    // 현재까지의 최대값 저장할 배열, 크기를 N으로 초기화
    int dp[N];
    //크기가 N인 배열을 입력받음
    for (int i = 0; i<N; i++)
        scanf("%d", &area[i]);
    //첫번째 값은 배열의 맨첫번째 값으로 설정
    ans = dp[0] = area[0];
    // 배열의 끝까지 탐색
    for(int i=1;i<N;i++){
        //현재 배열의 위치의 값과, 이전까지의 최대값 + 현재 의 값 에서 더 큰 수를 현재위치의 dp변수에 저장
        dp[i] = max(area[i],dp[i-1]+area[i]);
        //이전에 저장한 ans값보다 dp값이 크면 ans 값을 변경
        if (ans < dp[i]) ans = dp[i];
    }
    printf("%d\n",ans);
    return 0;
}