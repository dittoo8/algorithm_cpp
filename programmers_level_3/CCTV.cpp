#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
bool cmp(vector<int> a, vector<int> b){
    return a[1] < b[1];
} 
int solution(vector<vector<int> > routes) {
    int answer = 0;
    int limit = -30001;
    sort(routes.begin(),routes.end(),cmp);
    for(int i=0;i<routes.size();i++){
        if (limit < routes[i][0]){
            answer++;
            limit = routes[i][1];
        }
    }
    return answer;
}
int main(){
    vector<vector<int> > v;
    vector<int> v1;
    v1.push_back(-20);
    v1.push_back(15);
    vector<int> v2;
    v2.push_back(-14);
    v2.push_back(-5);
    vector<int> v3;
    v3.push_back(-18);
    v3.push_back(-13);
    vector<int> v4;
    v4.push_back(-5);
    v4.push_back(-3);
    v.push_back(v1);
    v.push_back(v2);
    v.push_back(v3);
    v.push_back(v4);
    cout << solution(v) <<endl;
    return 0;
}