#include <iostream>
#include <string>
#include <vector>
using namespace std;
long long solution(int n, vector<int> times) {
    long long answer = 0;
    long long s = (long long)times.size();
    long long min = 1;
    long long max = (long long)times[s-1]*n;
    answer= max;
    while(min<=max){
        long long mid = (min+max)/2;
        long long sum = 0;
        for(int i=0;i<s;i++){
            sum+=mid/times[i];
        }
        if(n>sum){
            min = mid+1;
        }else {
            if(mid<=answer){
                answer = mid;
                max = mid-1;
            }
        }
    }
    return answer;
}
int  main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector<int> v;
    v.push_back(7);
    v.push_back(10);
    cout << solution(6,v) << endl;
    return 0;
}