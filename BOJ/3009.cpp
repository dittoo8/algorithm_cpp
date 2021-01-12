#include <iostream>
using namespace std;
int x,y,n,m;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    for(int i=0;i<3;i++){
        cin >> x >> y;
        n^=x , m^=y;
    }
    cout << n << ' ' << m << '\n';
    return 0;
}