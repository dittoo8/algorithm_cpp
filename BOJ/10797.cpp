#include <iostream>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    char n,car;
    int cnt = 0;
    cin >> n;
    for(int i=0;i<5;i++){
        cin >> car;
        if(car == n) cnt++; 
    }
    cout << cnt << '\n';
    return 0;
}