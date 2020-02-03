#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n,k;
vector<pair<pair<int, int>, pair<int, int> > > a; 
bool cmp(pair<pair<int, int>, pair<int, int> > a, pair<pair<int, int>, pair<int, int> > b){
    if(a.first.second > b.first.second){
        //금메달 더 많으면 순위 높
        return true;
    } else if (a.first.second == b.first.second){
        // 금메달 같으면 은메달 많으면 순위 높
        if (a.second.first > b.second.first){
            return true;
        } else if (a.second.first == b.second.first){
            //금메달도 같고 은메달도 같으면 동메달 
            if(a.second.second > b.second.second){
                return true;
            } else if (a.second.second == b.second.second) {
                //다 같으면 같은 순위인데 어케처리하지
                return a.first.first == k;
            }
        }
    }
    return false;
}

int main(){
    cin >> n >> k;
    for(int i=1;i<=n;i++){
        int num, g,s,b;
        cin >> num >> g >> s>> b;
        a.push_back(make_pair(make_pair(num,g),make_pair(s,b)));

    }
    sort(a.begin(),a.end(),cmp);
    // for(int i=0;i<a.size();i++){
    //     printf("%d : %d %d %d\n",a[i].first.first, a[i].first.second, a[i].second.first, a[i].second.second);
    // }
    for(int i=0;i<n;i++){
        if (a[i].first.first == k) {
            cout << i+1 << endl;
            return 0;
        }
    }
    return 0;
}