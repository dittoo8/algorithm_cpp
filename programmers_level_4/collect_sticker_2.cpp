#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int d[100001][2];
int solution(vector<int> sticker){
    int n = (int)sticker.size();
    if (n==1) return sticker[0];
    if (n==2) return max(sticker[0],sticker[1]);
    d[0][0] = sticker[0];
    d[1][0] = sticker[0];
    d[1][1] = sticker[1];
    for(int i=2;i<sticker.size();i++){
        d[i][0]= max(d[i-2][0]+sticker[i],d[i-1][0]);
        d[i][1]= max(d[i-2][1]+sticker[i],d[i-1][1]);
    }
    return max(d[n-2][0],d[n-1][1]);
}
int main(){
    vector<int> v;
    v = {14,6,5,11,3,9,2,10};
    cout  << solution(v) << endl;
    return 0;
}