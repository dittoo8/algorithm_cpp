#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> A, vector<int> B) {
    int answer = 0;
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    if (A[0] >= B[B.size()-1]) return 0;
    int i = 0;
    for (int j=0;j<B.size();j++){
        if (A[i] < B[j]){
            i++;
            answer++;
        }
    }
    return answer;
}
int main(){
    vector<int> v1 = {5,1,3,7};
    vector<int> v2 = {2,2,6,8};
    cout << solution(v1,v2) <<endl;
    return 0;
}