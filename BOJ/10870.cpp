#include <iostream>
using namespace std;
int d[21];
int fib(int x){
    if (x == 1) return 1;
    if (x == 2) return 1;
    if (d[x]) return d[x];
    return d[x] = fib(x-1) + fib(x-2);
}
int main(){
    int n;
    cin >> n;
    if  (n ==0) {
        cout << 0 << '\n';
        return 0;
    }
    cout << fib(n) << '\n';
    return 0;
}