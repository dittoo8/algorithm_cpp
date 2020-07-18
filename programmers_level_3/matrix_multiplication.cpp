#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;
    for (int i = 0; i < arr1.size(); i++){
        vector<int> a;
        for (int t = 0; t < arr2[0].size(); t++){
            int sum = 0;
            for (int y = 0; y < arr1[0].size(); y++)
                sum += arr1[i][y] * arr2[y][t];
            a.push_back(sum);
        }
        answer.push_back(a);
    }
    return answer;
}
int main(){
    vector<vector<int> > v1 = {{1,4},{3,2},{4,1}};
    vector<vector<int> > v2 = {{3,3},{3,3}};
    vector<vector<int> > res = solution(v1,v2);
    for(int i=0;i<res.size();i++){
        for(int j=0;j<res[0].size();j++){
            cout << res[i][j] << " ";
        }
        cout << '\n';
    }
    return 0;
}