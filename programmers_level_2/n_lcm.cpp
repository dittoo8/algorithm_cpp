#include <iostream>
#include <string>
#include <vector>

using namespace std;
int gcd(int a, int b){
    return a%b == 0 ? b : gcd(b,a%b);
}
int lcm(int a, int b){
    return a*b/gcd(a,b);
}
int solution(vector<int> arr
) {
    int answer = 0;
    answer = arr[0];
    for(int i=1;i<arr.size();i++){
        answer = lcm(answer,arr[i]);
    }
    return answer;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<int> v;
    v.push_back(2);
    v.push_back(6);
    v.push_back(8);
    v.push_back(14);
    cout << solution(v) <<endl;
    return 0;
}