#include <iostream>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int H, D;
    int temp;
    cin >> H;
    cin >> temp;
    if(temp < H){
        H = temp;
    }
    cin >> temp;
    if(temp < H){
        H = temp;
    }
    cin >> D;
    cin>>temp;
    if(temp<D){
        D = temp;
    }
    cout << H + D -50;
    return 0;
}