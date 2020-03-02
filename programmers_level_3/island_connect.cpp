#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
vector<int> node;
int getParent(int x){
    if(node[x] == x) return x;
    return node[x] = getParent(node[x]);
}
int cycle(int a, int b){
    a = getParent(a);
    b = getParent(b);
    if( a == b) return 1;
    else return 0;
}
void unionParent(int a, int b){
    a = getParent(a);
    b = getParent(b);
    if(a<b) node[b] = a;
    else node[a] = b;

}
bool compare(vector<int> a, vector<int> b){
    return a[2] < b[2];
}
int solution(int n, vector<vector<int> > costs) {
    int answer = 0;
    sort(costs.begin(), costs.end(), compare);
    for(int i = 0; i < n; i++){
        node.push_back(i);
    }
    for(int i = 0; i < costs.size(); i++){
        if(!cycle(costs[i][0], costs[i][1])){
            answer += costs[i][2];
            unionParent( costs[i][0], costs[i][1]);
        }
    }
    return answer;
}
int main(){
    vector<vector<int> > v;
    vector<int> v1;
    v1.push_back(0);
    v1.push_back(1);
    v1.push_back(1);
    vector<int> v2;
    v2.push_back(0);
    v2.push_back(2);
    v2.push_back(2);
    vector<int> v3;
    v3.push_back(1);
    v3.push_back(2);
    v3.push_back(5);
    vector<int> v4;
    v4.push_back(1);
    v4.push_back(3);
    v4.push_back(1);
    vector<int> v5;
    v5.push_back(2);
    v5.push_back(3);
    v5.push_back(8);
    v.push_back(v1);
    v.push_back(v2);
    v.push_back(v3);
    v.push_back(v4);
    v.push_back(v5);
    cout << solution(4,v) << endl;
    return 0;
}