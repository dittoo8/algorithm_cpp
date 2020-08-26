#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct num {
    int cnt_3;
    long long number;
};
bool cmp(num &a, num &b){
    if (a.cnt_3 == b.cnt_3) return a.number < b.number;
    return a.cnt_3 > b.cnt_3;
}
int main(){
    long long temp;
    int n;
    cin >> n;
    vector<num> a(n);
    for(int i=0;i<n;i++){
        cin >> temp;
        a[i].number = temp;
        while(temp%3 == 0){
            temp/=3;
            a[i].cnt_3++;
        }
    }
    sort(a.begin(),a.end(),cmp);
    for(int i=0;i<n;i++){
        cout << a[i].number << ' ';
    }
    cout << '\n';
    return 0;
}