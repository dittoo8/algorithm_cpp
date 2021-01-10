#include <iostream>
#include <set>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    set<int> st;
    int x;
    for(int i=0;i<10;i++){
        cin >> x;
        st.insert(x%42);
    }
    cout << st.size() << '\n';
    return 0;
}