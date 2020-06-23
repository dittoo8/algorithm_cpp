#include <iostream>
using namespace std;
int s[1000001];
long long mods[10001];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    long long ans=0;
    cin >> n >> m;
    int temp,mod;
    mods[0]=1;
    for(int i=1;i<=n;i++){
        cin >> temp;
        s[i] = s[i-1]+temp;
        // s[i] : a[0] ~ a[i] 합의 나머지
        s[i]%=m;
        mods[s[i]]++;
    }
    for(int i=0;i<m;i++){
        //나머지가 같은 쌍 전부 추가
        ans+= mods[i]*(mods[i]-1)/2;
    }
    cout << ans << '\n';
    return 0;
}