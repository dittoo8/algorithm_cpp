#include <iostream>
#include <string>
#include <vector>
#define MOD 1234567
using namespace std;
long long d[100002];
long long dp(int x){
    if(x==0) return d[x] = 0;
    if(x==1) return d[x] = 1;
    if(d[x]!=0) return d[x];
    d[x] = (dp(x-1)+dp(x-2))%MOD;
    return d[x];
}
int solution(int n) {
    return dp(n);
}
int main(){
    cout << solution(5) << endl;
    return 0;
}