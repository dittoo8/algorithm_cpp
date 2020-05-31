#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int distance, vector<int> rocks, int n) {
    int answer = 0;
    sort(rocks.begin(),rocks.end());
    int left =1;
    int right = distance;
    while(left<=right){
        int mid = (left + right)/2;
        int remove = 0;
        int prev=0;
        for(int i=0;i<rocks.size();i++){
            if(rocks[i]-prev<mid) remove++;
            else prev = rocks[i];
        }
        if(distance -prev < mid) remove++;
        if (remove>n){
            right =mid-1;
        }else {
            left = mid+1;
            answer = answer <mid? mid:answer;
        }
    }
    return answer;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<int> v;
    v.push_back(2);
    v.push_back(14);
    v.push_back(11);
    v.push_back(21);
    v.push_back(17);
    cout << solution(25,v,2) <<endl;
    return 0;
}