#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define MAX 201
using namespace std;
int max_d[MAX][MAX];
int min_d[MAX][MAX];
int solution(vector<string> arr){
    int answer = 1;
    int num = (int)arr.size()/2 + 1;
    fill(&max_d[0][0], &max_d[MAX-1][MAX-1]+1,-1000000);
    fill(&min_d[0][0], &min_d[MAX-1][MAX-1]+1,1000000);
    for(int i=0;i<num;i++){
        max_d[i][i] = atoi(arr[i*2].c_str());
        min_d[i][i] = atoi(arr[i*2].c_str());
    }
    for(int calc = 1; calc< num;calc++){
        for(int i=0;i<num-calc;i++){
            int j= calc+i;
            for(int k=i;k<j;k++){
                if(arr[k*2+1]=="-"){
                    max_d[i][j] = max(max_d[i][k]-min_d[k+1][j],max_d[i][j]);
                    min_d[i][j] = min(min_d[i][k]-max_d[k+1][j],min_d[i][j]);
                }else {
                    max_d[i][j] = max(max_d[i][k]+max_d[k+1][j],max_d[i][j]);
                    min_d[i][j] = min(min_d[i][k]+min_d[k+1][j],min_d[i][j]);
                }
            }
        }
    }
    return max_d[0][num-1];
}
int main(){
    vector<string> v = {"5", "-", "3", "+", "1", "+", "2","-","4" };
    cout << solution(v) << endl;
    return 0;
}