#include <iostream>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    int mul = 1+2*(n-1);
    for(int i=0;i<n;i++){
        if(i+1 == n){
            for(int j=0;j<mul;j++){
                cout << '*';
            }
        }else {
            for(int j=0;j<=n+i-1;j++){
                if(j== n-i-1 || j== n+i-1){
                    cout << '*';
                }else {
                    cout << ' ';
                }
            }
        }
        cout << '\n';
    }
    return 0;
}