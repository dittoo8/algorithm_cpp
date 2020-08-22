#include <iostream>
#include <vector>
using namespace std;
vector<pair<int, int> > v;
void hanoi(int x,int s, int m, int e){
    if (x==0) return;
    cout << "first " << endl;
    hanoi(x-1,s,e,m);
    cout << "x : " << x << ", s: " << s <<", e : "<< e << '\n';
    v.push_back(make_pair(s,e));
    cout <<  "second  " << endl;
    hanoi(x-1,m,s,e);
}
int main(){
    int n;
    cin >> n;
    hanoi(n,1,2,3);
    // cout << (int)v.size() << '\n';
    // for(int i=0;i<v.size();i++){
    //     cout << v[i].first <<' ' << v[i].second << '\n';
    // }
    return 0;
}