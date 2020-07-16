#include <iostream>
#include <string>
#include <vector>

using namespace std;

double solution(vector<int> arr) {
    double answer = 0;
    for(int i=0;i<arr.size();i++){
        answer+=arr[i];
    }
    return answer/arr.size();
}
int main(){
    vector<int> v = {1,2,3,4};
    cout << solution(v) << endl;
    return 0;
}