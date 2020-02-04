#include <iostream>
#include <string>
#include <vector>

using namespace std;
int cnt;
void dfs(vector<int> numbers, int target, int x, int depth,int i){
    if(depth == i && x == target) cnt++;
    else if(depth > i){
        dfs(numbers,target,x+numbers[i],depth, i+1);
        dfs(numbers,target,x-numbers[i],depth, i+1);
    }
}
int solution(vector<int> numbers, int target) {
    int answer = 0;
    int numSize = numbers.size();
    dfs(numbers, target, 0, numSize,0);
    answer = cnt;
    return answer;
}
int main(){
    vector<int> v;
    v.push_back(1);
    v.push_back(1);
    v.push_back(1);
    v.push_back(1);
    v.push_back(1);
    cout << solution(v,3) << endl;
    return 0;

}