#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
int lastInt;
set<int> st;
bool Dec[10000000];
void find_decimal(){
    for(int i=2;i*i<=lastInt;i++){
        if(Dec[i]) continue;
        for(int j=i+i;j<=lastInt;j+=i){
            Dec[j] = true;
        }
    }
}
int solution(string numbers) {
    int answer = 0;
    Dec[0]=true;
    Dec[1]=true;
    sort(numbers.begin(),numbers.end());
    string lastStr = numbers;
    reverse(lastStr.begin(),lastStr.end());
    lastInt = stoi(lastStr);
    find_decimal();
    do {
        for(int i=1;i<=numbers.size();i++){
            st.insert(stoi(numbers.substr(0,i)));
        }
    }while (next_permutation(numbers.begin(),numbers.end()));
    for(auto it = st.begin();it!=st.end();it++){
        if(!Dec[*it]) {
            answer++;
        }
    }
    return answer;
}
int main(){
    cout << solution("17") << endl;
    return 0;
}