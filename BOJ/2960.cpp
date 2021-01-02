#include <iostream>
using namespace std;
bool isDel[1001];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, k,cnt=0;
    cin >> n >> k;
    for(int i=2;i<=n;i++){
        if(isDel[i]) continue;
        for(int j=i;j<=n;j+=i){
            if(isDel[j]==false){
                isDel[j] = true;
                cnt++;
                if(cnt == k) {
                    cout << j <<'\n';
                    break;
                }
            }
        }
    }
    return 0;
}