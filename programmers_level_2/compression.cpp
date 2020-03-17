#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    map<string, int> mp;
    for(int i=0;i<26;i++){
        char c = 'A'+i;
        string str = "";
        str+=c;
        mp[str] = i+1;
    }
    int k =27;
    int i=0;
    while(i<=msg.length()-1){
        int j = 1;
        while(mp[msg.substr(i,j)]&& (i+j <=msg.length())){
            j++;
        }
        answer.push_back(mp[msg.substr(i,j-1)]);
        cout << mp[msg.substr(i,j-1)] << endl;
        mp[msg.substr(i,j)]=k;
        k++;
        i+=j-1;
    }

    return answer;
}
int main(){
    vector<int> v;
    v = solution("ABABABABABABABAB");
    for(int i=0;i<v.size();i++){
        cout << v[i] << " ";
    }
    return 0;
}