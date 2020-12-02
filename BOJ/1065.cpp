#include <iostream>
#include <string>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n,cnt = 0;
    cin >> n;
    if(n>=100){
        cnt+=99;
        for(int i=100;i<=n && i<1000;i++){
            string now = to_string(i);
            if(now[1]-now[0] == now[2]-now[1]) cnt++;
        }
    }else {
        cnt+=n;
    }
    cout << cnt << '\n';
    return 0;
}