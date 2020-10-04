#include <iostream>
using namespace std;
bool ck[10001];
void check_prime(int x){
    for(int i=2;i*i<=x;i++){
        if(ck[i]) continue;
        for(int j = i*2;j<=x;j+=i){
            ck[j] = true;
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int m,n;
    cin >> m >> n;
    check_prime(n);
    int sum = 0,mn = -1;
    ck[0] = true;
    ck[1] = true;
    for(int i=m;i<=n;i++){
        if(!ck[i]){
            sum+=i;
            if(mn == -1) mn = i;
        }
    }
    if (mn == -1){
        cout << -1 << '\n';
    }else {
        cout << sum <<'\n';
        cout << mn << '\n';
    }
    return 0;
}