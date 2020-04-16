#include <vector>
#include <iostream>
using namespace std;
bool ck[3001];
int solution(vector<int> nums) {
    int answer = 0;
    for(int i=2;i<3000;i++){
        for(int j=i*2;j<3000;j+=i){
            if (ck[j]) continue;
            ck[j]=true;
        }
    }
    int ns = nums.size();
    for(int i=0;i<ns;i++){
        for(int j=i+1;j<ns;j++){
            for(int k=j+1;k<ns;k++){
                if (!ck[nums[i]+nums[j]+nums[k]]) answer++;
            }
        }
    }

    return answer;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(7);
    v.push_back(6);
    v.push_back(4);
    cout << solution(v) <<endl;
    return 0;
}