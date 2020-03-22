#include <iostream>
using namespace std;
int gcd(int x, int y){
    while(y!=0){
        int r = x%y;
        x=y;
        y=r;
    }
    return x;
}
int lcm(int x, int y){
    return (x*y)/gcd(x,y);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int a, b;
    cin >> a >> b;
    cout << gcd(a,b) << endl;
    cout << lcm(a,b) << endl;
    return 0;
}