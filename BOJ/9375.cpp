#include <iostream>
#include <string>
#include <map>
#include <set>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    map<string, int> mp;
    set<string> st;
    int tc,n,ans;
    cin >> tc;
    while(tc--){
        mp.clear();
        st.clear();
        ans = 1;
        cin >> n;
        string name,type;
        for(int i=0;i<n;i++){
            cin >> name >> type;
            mp[type]++;
            st.insert(type);
        }
        set<string>::iterator iter;
        for(iter = st.begin(); iter!=st.end(); ++iter){
            ans*= mp[*iter]+1;
        }
        cout << ans-1 << '\n';
    }
    return 0;
}