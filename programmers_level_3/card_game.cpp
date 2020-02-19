#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
vector<int> l,r;
int d[2002][2002];
int Vsize;
int dp(int i, int j){
    if (i==Vsize || j == Vsize) return 0;
    if(d[i][j]>0) return d[i][j];
    d[i][j] = max(dp(i+1,j),dp(i+1,j+1));
    if (l[i]>r[j]){
        d[i][j] = max(d[i][j], dp(i,j+1)+r[j]);
    }
    return d[i][j];
}
int solution(vector<int> left, vector<int> right) {
    l = left; r = right;
    Vsize = left.size();
    return dp(0,0);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector<int> left;
    left.push_back(3);
    left.push_back(2);
    left.push_back(5);
    vector<int> right;
    right.push_back(2);
    right.push_back(4);
    right.push_back(1);

    cout << solution(left, right) << endl;
    return 0;
}