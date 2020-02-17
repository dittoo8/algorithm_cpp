#include <iostream>
#include <string>
#include <vector>
using namespace std;
long long d[81];
long long dp(int n){
    if (n==1) return d[1] = 4;
    if (n==2) return d[2] = 6;
    if (n==3) return d[3] = 10;
    if (d[n]!=0) return d[n];
    return d[n] = dp(n-1)*2-dp(n-3);
    
}
long long solution(int N) {
    return dp(N);
}
int main(){
    cout << solution(5) << endl;
    return 0;
}