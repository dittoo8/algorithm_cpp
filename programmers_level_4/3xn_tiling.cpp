#include <iostream>
#include <string>
#include <vector>
#define MOD 1000000007
using namespace std;
long long d[5001];
int solution(int n) {
    d[0]=1;
    d[2]=3;
    d[4]=11;
    for(int i=6;i<=n;i+=2){
        d[i] = d[i-2]*3;
        for(int j= i-4;j>=0;j-=2){
            d[i]+= d[j]*2;
        }
        d[i]%=MOD;
    }
    return d[n];
}
int main(){
    cout << solution(4) <<endl;
    return 0;
}