#include <iostream>
#include <string>
#include <vector>
#define MOD 1234567
using namespace std;
long long d[2001];
long long solution(int n) {
    long long answer = 0;
    d[1]=1;
    d[2]=2;
    for(int i=3;i<=n;i++){
        d[i]= (d[i-1]+d[i-2])%MOD;
    }
    return d[n];
}
int main(){
    cout << solution(4) <<endl;
    return 0;
}