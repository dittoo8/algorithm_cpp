#include <iostream>
#include <string>
#include <vector>
#define MOD 1000000007
using namespace std;
int d[60001];

int solution(int n) {
    int answer = 0;
    d[1]=1;
    d[2]=2;
    for(int i=3;i<=n;i++){
        d[i]=(d[i-1]+d[i-2])%MOD;
    }
    return d[n];
}
int main(){
    cout << solution(4) << endl;
    return 0;
}