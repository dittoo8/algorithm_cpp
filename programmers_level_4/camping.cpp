#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int solution(int n, vector<vector<int> > data){
    int answer = 0;
    sort(data.begin(),data.end());
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if (data[i][0]==data[j][0] || data[i][1]==data[j][1]) continue;
            for(int k=j-1;k>i;k--){
                if (data[k][0] < max(data[i][0],data[j][0])
                && data[k][0] > min(data[i][0],data[j][0])
                && data[k][1] < max(data[i][1],data[j][1])
                && data[k][1] > min(data[i][0],data[j][0])){
                    answer--;
                    break;
                }
            }
            answer++;
        }
    }
    return answer;
}
int main(){
    vector<vector<int> > v = {
        {0,0},{1,1},{0,2},{2,0}
    };
    cout << solution(4,v) << endl;
    return 0;
}