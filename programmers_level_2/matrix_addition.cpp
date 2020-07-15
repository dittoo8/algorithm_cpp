#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;
    for(int i=0;i<arr1.size();i++){
        for(int j=0;j<arr1[0].size();j++){
            arr1[i][j]+=arr2[i][j];
        }
    }
    return arr1;
}
int main(){
    vector<vector<int> > v1 = {{1,2},{2,3}};
    vector<vector<int> > v2 = {{3,4},{5,6}};
    vector<vector<int> > res = solution(v1,v2);
    for(int i=0;i<res.size();i++){
        for(int j=0;j<res[0].size();j++){
            cout << res[i][j]<<" ";
        }
        cout << endl;
    }
    return 0;
}