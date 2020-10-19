#include <iostream>
#include <set>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    set<long long> st;
    int n, m;
    cin >> n;
    long long num;
    for(int  i=0;i<n;i++){
        cin >> num;
        st.insert(num);
    }
    cin >> m;
    for(int i=0;i<m;i++){
        cin >> num;
        if(st.find(num)!=st.end()){
            cout << 1 << ' ';
        }else cout << 0 <<' ';
    }
    cout << endl;
    return 0;
}