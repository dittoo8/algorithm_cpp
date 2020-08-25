#include <iostream>
#include <set>
using namespace std;
int main(){
    set<int> st;
    int n;
    cin >> n;
    for(int i=0;i<=n;i++){ //I 갯수
        for(int j=0;j<=n-i;j++){ // V 갯수
            for(int k=0;k<=n-i-j;k++){ // X 갯수
                int l = n-i-j-k;  // L 갯수
                st.insert(i+j*5+k*10+l*50);
            }
        }
    }
    cout << (int)st.size() << '\n';
    return 0;
}