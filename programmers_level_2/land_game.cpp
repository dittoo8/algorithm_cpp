#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int d[100002][4];
int max3(int a, int b, int c){
    if (a < b) {
        return max(b,c);
    } else return max(a,c);
}
int solution(vector<vector<int> > land)
{
    int answer = 0;
    d[0][0]=land[0][0];
    d[0][1]=land[0][1];
    d[0][2]=land[0][2];
    d[0][3]=land[0][3];
    for(int i=1;i<land.size();i++){
        d[i][0] = max3(d[i-1][1],d[i-1][2],d[i-1][3]) + land[i][0];
        d[i][1] = max3(d[i-1][0],d[i-1][2],d[i-1][3]) + land[i][1];
        d[i][2] = max3(d[i-1][0],d[i-1][1],d[i-1][3]) + land[i][2];
        d[i][3] = max3(d[i-1][0],d[i-1][1],d[i-1][2]) + land[i][3];
    }
    int lastIdx = land.size()-1;
    for(int i=0;i<4;i++){
        if (answer < d[lastIdx][i]) answer = d[lastIdx][i];
    }
    return answer;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector<vector<int> > v;
    vector<int> v1;
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);
    v1.push_back(5);
    vector<int> v2;
    v2.push_back(5);
    v2.push_back(6);
    v2.push_back(7);
    v2.push_back(8);
    vector<int> v3;
    v3.push_back(4);
    v3.push_back(3);
    v3.push_back(2);
    v3.push_back(1);
    v.push_back(v1);
    v.push_back(v2);
    v.push_back(v3);
    cout << solution(v) <<endl;
    
    return 0;
}
