#include <iostream>
#include <string>
#include <vector>
#define MOD 1000000007
using namespace std;
int d[101][101];
int solution(int m, int n, vector<vector<int> > puddles) {
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            d[i][j] = 1;
        }
    }
    for(int i=0;i<puddles.size();i++){
        d[puddles[i][1]][puddles[i][0]] = 0;
        if(puddles[i][0]==1) {
            //j가 1일때
            for(int j=puddles[i][1];j<=n;j++){
                d[j][1]=0;
            }
        }
        if(puddles[i][1]==1) {
            //i가 1일때
            for(int j=puddles[i][0];j<=m;j++){
                d[1][j]=0;
            }
            
        }
    }
    for(int i=2;i<=n;i++){
        for(int j=2;j<=m;j++){
            if (d[i][j]!=0){
                d[i][j] = (d[i-1][j]+d[i][j-1])%MOD;
            }
        }
    }
    return d[n][m];
}
int main(){
    vector<vector<int> > v;
    vector<int> v1;
    v1.push_back(2);
    v1.push_back(2);
    v.push_back(v1);
    cout << solution(4,3,v) << endl;
    return 0;
}