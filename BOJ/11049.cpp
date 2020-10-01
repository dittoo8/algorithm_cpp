#include <iostream>
#include <vector>
#include <algorithm>
#define INF 987654321
#define MAX 505
using namespace std;
int d[MAX][MAX];
vector<pair<int, int> > v;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n,x,y;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> x >> y ;
        v.push_back(make_pair(x,y));
    }
    for(int i=n-1;i>=0;i--){
        for(int j=i+1;j<n;j++){
            d[i][j]= INF;
            for(int k=i;k<=j;k++){
                d[i][j] = min(d[i][j],d[i][k]+d[k+1][j]+v[i].first*v[k].second*v[j].second);
            }
        }
    }
    cout << d[0][n-1] << '\n';
    return 0;
}