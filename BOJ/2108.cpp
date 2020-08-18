#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <math.h>
using namespace std;
int main(){
    map<int, int> mp;
    int n,maxCnt=0;
    int a[500001];
    long long avg=0;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a[i];
        avg+=a[i];
        mp[a[i]]++;
        if (mp[a[i]]>maxCnt) {
            maxCnt = mp[a[i]];
        }
    }
    vector<int> maxA;
    sort(a,a+n);
    for(auto it = mp.begin();it!= mp.end();it++){
        if (it-> second == maxCnt){
            maxA.push_back(it->first);
        }
    }
    sort(maxA.begin(),maxA.end());

    cout << (int)round(avg / double(n)) << '\n';
    cout << a[n/2] << '\n';
    if (maxA.size()> 1){
        cout << maxA[1] << '\n';
    }else cout << maxA[0] << '\n';
    cout << a[n-1]-a[0] <<'\n';
    return 0;
}