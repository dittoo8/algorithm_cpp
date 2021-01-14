#include <iostream>
#include <string>
#define INF 987654321
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int cnt = 0, ans = INF;
    string a,b;
    cin >> a >> b;
    for(int i=0;i<=b.size()-a.size();i++){
        cnt = 0;
        for(int j=0;j<a.size();j++){
            if(a[j]!=b[j+i]) cnt++;
        }
        if(ans > cnt){
            ans = cnt;
        }
    }
    cout << ans << '\n';
    return 0;
}