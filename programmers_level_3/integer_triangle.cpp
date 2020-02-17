#include <iostream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int d[501][501];
int solution(vector<vector<int> > triangle) {
    int answer = 0;
    d[0][0] = triangle[0][0];
    for(int i=0;i<triangle.size()-1;i++){
        for(int j=0;j<triangle[i].size();j++){
            d[i+1][j] = max(d[i+1][j],triangle[i+1][j]+d[i][j]);
            d[i+1][j+1] = max(d[i+1][j+1],triangle[i+1][j+1]+d[i][j]);
        }
    }
    int Size = (int)triangle.size();
    int res = 0;
    for(int i=0;i<triangle[Size-1].size();i++){
        res = max(res, d[Size-1][i]);
    }
    return res;
}
int main(){
    vector<vector<int> > v;
    vector<int> v1;
    v1.push_back(7);
    vector<int> v2;
    v2.push_back(3);
    v2.push_back(8);
    vector<int> v3;
    v3.push_back(8);
    v3.push_back(1);
    v3.push_back(0);
    vector<int> v4;
    v4.push_back(2);
    v4.push_back(7);
    v4.push_back(4);
    v4.push_back(4);
    vector<int> v5;
    v5.push_back(4);
    v5.push_back(5);
    v5.push_back(2);
    v5.push_back(6);
    v5.push_back(5);
    v.push_back(v1);
    v.push_back(v2);
    v.push_back(v3);
    v.push_back(v4);
    v.push_back(v5);
    cout << solution(v) << endl;
    return 0;
}