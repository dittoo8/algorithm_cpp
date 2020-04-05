#include <iostream>
#include <string>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for(int j=1;j<=t;j++){
        int n,res=0;
        cin >> n;
        string a;
        string b;
        cin >> a;
        cin >> b;
        for(int i=0;i<n;i++){
            if (a[i]==b[i]) res++;
        }
        cout << "#"<<j <<" " <<res <<endl;
    }
    return 0;
}