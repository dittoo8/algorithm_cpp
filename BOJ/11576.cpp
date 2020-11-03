#include <iostream>
#include <vector>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int a, b,m;
    int nums[26] = {};
    cin >> a >> b >> m ;
    for(int i=0;i<m;i++){
        cin >> nums[i];
    }
    int tmp =0, mul = 1;
    for(int i=0;i<m;i++){
        tmp += mul*nums[m-1-i];
        mul*=a;
    }
    vector<int> ans;
    while(tmp){
        ans.push_back(tmp%b);
        tmp/=b;
    }
    for(int i=0;i<ans.size();i++){
        cout << ans[ans.size()-1-i] << ' ';
    }
    return 0;
}