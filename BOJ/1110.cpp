#include <iostream>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int num, res;
    int a,b,c,d;
    int cnt = 0;
    cin >> num;
    res = num;
    while(true){
        a = num/10;
        b = num%10;
        c = (a+b)%10;
        d = (b*10)+c;
        num = d;
        cnt++;
        if(d == res) break;
    }
    cout << cnt << '\n';
    return 0;
}