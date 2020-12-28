#include <iostream>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int a,sum=0,mn=100;
    for(int i=0;i<7;i++){
        cin >> a;
        if(a%2 == 1) {
            sum+=a;
            if(mn > a) mn = a;
        }
    }
    if( sum == 0){
        cout << -1 << '\n';
    }else {
        cout << sum << '\n';
        cout << mn << '\n';
    }
    return 0;
}