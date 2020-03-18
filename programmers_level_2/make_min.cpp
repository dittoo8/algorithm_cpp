#include <iostream>
#include<vector>
#include <algorithm>
using namespace std;
bool cmp (int a, int b){
    return a> b;
}
int solution(vector<int> A, vector<int> B)
{
    int answer = 0;
    sort(A.begin(),A.end());
    sort(B.begin(),B.end(),cmp);
    for(int i=0;i<A.size();i++){
        answer+= (A[i]*B[i]);
    }

    return answer;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector<int> a;
    a.push_back(1);
    a.push_back(4);
    a.push_back(2);
    vector<int> b;
    b.push_back(5);
    b.push_back(4);
    b.push_back(4);
    cout << solution(a,b)<<endl;
    return 0;
}