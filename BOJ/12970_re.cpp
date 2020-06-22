#include <iostream>
#include <vector>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,k;
    cin >> n >> k;
    for(int a=0;a<=n;a++){
        int b= n-a;
        if (a*b < k) continue;
        vector<int> cnt(b+1);
        for(int i=0;i<a;i++){
            int x = min(b,k);
            cnt[x]+=1;
            k-=x;
        }
        for(int i=b;i>=0;i--){
            for(int j=0;j<cnt[i];j++){
                cout  << 'A';
            }
            if (i>0){
                cout << 'B';
            }
        }
        cout << '\n';
        return 0;
    }
    cout << -1 << '\n';
    return 0;
}