#include <iostream>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int a, b;
    cin >> a >> b;
    int c = 0, d = 0;
    while(a){
        c*=10;
        c += a % 10;
        a /= 10;
    }
    while(b){
        d *=10;
        d += b %10;
        b /=10;
    }
    if( c > d) cout <<  c << '\n';
    else cout << d << '\n';
    return 0;
}