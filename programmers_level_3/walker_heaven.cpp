#include <iostream>
#include <vector> 
#include <cstring>

using namespace std;

int MOD = 20170805;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int r[501][501];
int b[501][501];
int solution(int m, int n, vector<vector<int> > city_map) {
    memset(r, 0, sizeof r);
    memset(b, 0, sizeof b);
    MOD = 20170805;
    r[1][1] = b[1][1] = 1;
    for(int i=1; i<=m;i++){   
        for(int j=1;j<=n;j++){
            if(city_map[i-1][j-1]==0){
                r[i][j] = (r[i][j] + r[i][j-1] + b[i-1][j])%MOD;
                b[i][j] = (b[i][j] + r[i][j-1] + b[i-1][j])%MOD;
            }
            else if(city_map[i-1][j-1]==1){
                r[i][j] = 0;
                b[i][j] = 0;
            }
            else{
                r[i][j] = r[i][j-1];
                b[i][j] = b[i-1][j];              
            }
        }
    }
    return (r[m][n-1]+b[m-1][n])%MOD;
}
int main(){
    vector<vector<int> > v;
    vector<int> v1;
    v1.push_back(0);
    v1.push_back(2);
    v1.push_back(0);
    v1.push_back(0);
    v1.push_back(0);
    v1.push_back(2);
    vector<int> v2;
    v2.push_back(0);
    v2.push_back(0);
    v2.push_back(2);
    v2.push_back(0);
    v2.push_back(1);
    v2.push_back(0);
    vector<int> v3;
    v3.push_back(1);
    v3.push_back(0);
    v3.push_back(0);
    v3.push_back(2);
    v3.push_back(2);
    v3.push_back(0);
    v.push_back(v1);
    v.push_back(v2);
    v.push_back(v3);
    cout << solution(3,6,v) << endl;
    return 0;
}