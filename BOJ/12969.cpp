#include <iostream>
#include <string>
using namespace std;
int N,K;
bool visit[436][31][31][31]; //k,n,a,b
char str[31];
bool backtrack(int k, int n, int a, int b){
    if (n==N){
        if (k==K) return true;
        else return false;
    }
    if(visit[k][n][a][b]) return false;
    visit[k][n][a][b]=true;
    str[n]='A';
    if(backtrack(k,n+1,a+1,b)){
        return true;
    }
    str[n]='B';
    if(backtrack(k+a,n+1,a,b+1)){
        return true;
    }
    str[n]='C';
    if(backtrack(k+a+b,n+1,a,b)){
        return true;
    }
    return false;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> K;
    if(backtrack(0,0,0,0)){
        cout << str <<endl;
    }else cout << -1 <<endl;
    return 0;
}
