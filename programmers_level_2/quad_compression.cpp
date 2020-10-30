#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<int> answer;
void divide_map(vector<vector<int> > &a, int x, int y ,int s){
    if(s<1) return;
    int num = a[x][y];
    for(int i=x;i<x+s;i++){
        for(int j=y;j<y+s;j++){
            if (a[i][j]!=num){
                divide_map(a,x,y,s/2);
                divide_map(a,x+s/2,y,s/2);
                divide_map(a,x,y+s/2,s/2);
                divide_map(a,x+s/2,y+s/2,s/2);
                return;
            }
        }
    }
    answer[num]++;
}
vector<int> solution(vector<vector<int>> arr) {
    answer.resize(2);
    int s = (int)arr.size();
    divide_map(arr,0,0,s);
    return answer;
}
int main(){
    vector<vector<int> > v = {{1,1,0,0},{1,0,0,0},{1,0,0,1},{1,1,1,1}};
    vector<int> ans = solution(v);
    cout << ans[0] << ' ' << ans[1] << endl;
    return 0;
}