#include <iostream>
#include <string>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc,cnt;
    cin >> tc;
    while(tc--){
        string a,b;
        cnt = 0;
        cin >> a >> b;
        for(int i=0;i<a.length();i++){
            if (a[i] != b[i]) cnt++;
        }
        cout << "Hamming distance is " << cnt << "." << '\n';
    }
    return 0;
}