#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
bool cmp(string a, string b){
    //길이 짧은거 먼저
    if (a.length() != b.length()) return a.length() < b.length();
    else{
        //길이 같으면 자리수 합 작은거 먼저
        int tempA = 0, tempB=0;
        for(int i=0;i<a.length();i++){
            if (a[i]>='0' && a[i]<='9'){
                tempA+=a[i]-'0';
            }
        }
        for(int i=0;i<b.length();i++){
            if (b[i]>='0' && b[i]<='9'){
                tempB+=b[i]-'0';
            }
        }
        if (tempA != tempB) return tempA < tempB;
        else return a< b;
    }
}
int main(){
    int n;
    vector<string> v;
    cin >> n;
    for(int i=0;i<n;i++) {
        string a;
        cin >> a;
        v.push_back(a);
    }
    sort(v.begin(),v.end(),cmp);
    for(int i=0;i<v.size();i++){
        cout << v[i] << endl;
    }
    return 0;
}