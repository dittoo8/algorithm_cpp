#include <iostream>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n,a,b;
    cin >> n >> a >> b;
    for(int i=1;;i++){
        n++,a++,b++;
        if(a/2 == b/2){
            cout << i << '\n';
            break;
        }
        n/=2,a/=2,b/=2;
    }
    return 0;
}