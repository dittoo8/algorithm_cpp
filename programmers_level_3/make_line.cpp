#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, long long k) {
    vector<int> answer;
    vector<int> people;
    long long fec = 1; k--;
    for(int i=1;i<=n;i++){
        fec *= i;
        people.push_back(i);
    }
    while(n>0){
        fec = fec/ n;
        n--;
        answer.push_back(people[k/fec]);
        people.erase(people.begin()+k/fec);
        k %= fec;
    }
    return answer;
}
int main(){
    vector<int> v;
    v = solution(3,5);
    for(int i=0;i<v.size();i++){
        cout << v[i] << ' ';
    }
    return 0;
}