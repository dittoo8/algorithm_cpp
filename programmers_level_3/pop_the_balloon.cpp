#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> a) {
    int answer = 0;
    vector<int> pre_min(a.size()+1);
    vector<int> suf_min(a.size()+1);
    pre_min[0]=a[0];
    suf_min[a.size()-1] = a[a.size()-1];
    for(int i=1;i<a.size();i++){
        pre_min[i] = min(pre_min[i-1],a[i]);
    }
    for(int i=a.size()-2;i>=0;i--){
        suf_min[i] = min(suf_min[i+1],a[i]);
    }
    for(int i=0;i<a.size();i++){
        if(pre_min[i] >= a[i] || suf_min[i] >= a[i]) answer++;
    }
    return answer;
}
int main(){
    vector<int> v = {-16,27,65,-2,58,-92,-71,-68,-61,-33};
    cout << solution(v) << endl;
    return 0;
}