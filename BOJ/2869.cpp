#include <iostream>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int a, b, v,temp, n;
    cin >> a >> b >> v;
    temp = v - a;
    n = temp / (a - b);
    if(temp % (a - b) != 0) ++n;
    cout << ++n << '\n';
    return 0;
}