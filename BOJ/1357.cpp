#include <iostream>
using namespace std;
int rev(int x){
    int r = 0;
    while(x){
        r*=10;
        r+=x%10;
        x/=10;
    }
    return r;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int a, b;
    cin >> a >> b;
    cout << rev(rev(a)+rev(b)) << '\n';
    return 0;
}