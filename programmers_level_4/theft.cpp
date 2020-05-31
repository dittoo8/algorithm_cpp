#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define MAX 1000001
using namespace std;
int dp[2][MAX];
int solution(vector<int> money) {
    int answer = 0;
    int mSize = (int)money.size();
    dp[0][0]=money[0];
    dp[1][1]=money[1];
    for(int i=1;i<mSize-1;i++){
        dp[0][i] = max(money[i]+dp[0][i-2],dp[0][i-1]);
    }
    for(int i=2;i<mSize;i++){
        dp[1][i] = max(money[i]+dp[1][i-2],dp[1][i-1]);
    }
    return max(dp[0][mSize-2],dp[1][mSize-1]);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(1);
    cout << solution(v) <<endl;
    return 0;
}