#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        vector<pair<int ,int> > rank;
        int n;
        cin >> n;
        for(int i=0;i<n;i++){
            int a,b;
            cin >> a >> b;
            rank.push_back(make_pair(a,b));
        }
        sort(rank.begin(),rank.end());
        int min = 100002;
        int cnt = 0;
        for(int i=0;i<rank.size();i++){
            if(min > rank[i].second) {
                min = rank[i].second;
                cnt++;
            }
        }
        cout << cnt << endl;
    }
    return 0;
}