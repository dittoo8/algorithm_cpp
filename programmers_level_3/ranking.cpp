#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
#define INF 987654321
using namespace std;
int d[101][101];
int solution(int n, vector<vector<int> > results) {
    int answer = 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j){
                d[i][j] = 0;
            }else {
                d[i][j] = INF;
            }
        }
    }
    for(int i=0;i<results.size();i++){
        d[results[i][0]][results[i][1]] = 1;
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if (d[i][j] > d[i][k]+d[k][j]){
                    d[i][j] = d[i][k]+d[k][j];
                }
            }
        }
    }
    bool check[101];
    memset(check,true,sizeof(check));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if (d[i][j] ==INF && d[j][i]==INF){
                check[i] = false;
                break;
            }
        }
    }
    for(int i=1;i<=n;i++){
        if (check[i]) answer++;
    }
    return answer;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector<vector<int> > v;
    vector<int> v1;
    v1.push_back(4);
    v1.push_back(3);
    vector<int> v2;
    v2.push_back(4);
    v2.push_back(2);
    vector<int> v3;
    v3.push_back(3);
    v3.push_back(2);
    vector<int> v4;
    v4.push_back(1);
    v4.push_back(2);
    vector<int> v5;
    v5.push_back(2);
    v5.push_back(5);
    v.push_back(v1);
    v.push_back(v2);
    v.push_back(v3);
    v.push_back(v4);
    v.push_back(v5);

    cout << solution(5,v) << endl;
    return 0;
}