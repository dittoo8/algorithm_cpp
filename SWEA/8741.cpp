#include <iostream>
#include <vector>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tc;
    cin >> tc;
    vector<string> str;
    string s;
    cin.ignore();
    for(int i=0;i<tc;i++){
        getline(cin,s);
        str.push_back(s);
    }
    for(int t=0;t<tc;t++){
        string  res = "";
        res+= (char)str[t][0]-32;
        for(int i=1;i<str[t].length();i++){
            if (str[t][i]==' ') {
                i++;
                res+=(char)str[t][i]-32;
            }
        }
        cout << "#"<<t+1 <<" "<<res<<endl;
    }
    return 0;
}