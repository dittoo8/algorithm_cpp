#include <iostream>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int x, y;
    cin >> x >> y;
    if (x > 0){
        if (y > 0){
            cout << 1 << '\n';
        }else {
            cout << 4 << '\n';
        }
    } else {
        if (y > 0){
            cout << 2 << '\n';
        }else {
            cout << 3 << '\n';
        }
    }
    return 0;
}