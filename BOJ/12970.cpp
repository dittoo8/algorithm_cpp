#include <iostream>
#include <string>
using namespace std;
int N,K;
bool visit[1226][51][51]; //k,n,a
char str[51];
bool backtrack(int k, int n, int a){
    if (n==N){
        if (k==K) return true;
        else return false;
    }
    if(visit[k][n][a]) return false;
    visit[k][n][a]=true;
    str[n]='A';
    if(backtrack(k,n+1,a+1)){
        return true;
    }
    str[n]='B';
    if(backtrack(k+a,n+1,a)){
        return true;
    }
    return false;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> K;
    if(backtrack(0,0,0)){
        cout << str <<endl;
    }else cout << -1 <<endl;
    return 0;
}
