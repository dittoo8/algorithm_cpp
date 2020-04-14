#include <iostream>
#include <string>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tc;
    cin >> tc;
    for(int t=1;t<=tc;t++){
        int ck[10] = {0,};
        int res=0;
        string str;
        cin >> str;
        for(int i=0;i<str.length();i++){
            int now = str[i]-'0';
            ck[now]++;
        }
        for(int i=0;i<10;i++){
            if (ck[i]%2==1) res++;
        }
        cout << "#"<< t <<" "<<res<<endl;
    }
    return 0;
}