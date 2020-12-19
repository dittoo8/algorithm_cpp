#include <iostream>
#include <string>
#include <map>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n,m;
    cin >> n >> m;
    string str[100001];
    map<string, int> mp;
    for(int i=1;i<=n;i++){
        cin >> str[i];
        mp[str[i]] = i;
    }
    string x;
    for(int i=0;i<m;i++){
        cin >> x;
        if(x[0]>='0'&&x[0]<='9'){
            cout << str[stoi(x)] << '\n';
        }else{
            cout << mp[x] << '\n';
        }
    }
    return 0;
}