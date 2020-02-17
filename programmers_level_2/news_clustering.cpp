#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
using namespace std;

int solution(string str1, string str2) {
    long long answer = 0;
    transform(str1.begin(), str1.end(), str1.begin(), ::tolower);
    transform(str2.begin(), str2.end(), str2.begin(), ::tolower);
    vector<string> newA;
    vector<string> newB;
    string tempA="";
    string tempB ="";
    for(int i=0;i<str1.length()-1;i++){
         if(isalpha(str1[i]) && isalpha(str1[i+1])){
             newA.push_back(str1.substr(i,2));
         }
    }
    for(int i=0;i<str2.length()-1;i++){
        if(isalpha(str2[i]) && isalpha(str2[i+1])){
             newB.push_back(str2.substr(i,2));
         }
    }
    int uniSize = 0, interSize = 0;
    sort(newA.begin(),newA.end());
    sort(newB.begin(), newB.end());
    int i=0,j=0;
    if(!(newA.size()==0 || newB.size()==0)){
        while(1){
            if (i==newA.size() ||j==newB.size()) break;
            if(newA[i]==newB[j]){ interSize++; i++; j++; }
            else if (newA[i]>newB[j]){ j++; }
            else if (newA[i]<newB[j]){ i++; }
            uniSize++;
        }
    }
    if (i < newA.size()){
        uniSize+=newA.size()-i;
    }
    if (j < newB.size()){
        uniSize+=newB.size()-j;
    }
    if (uniSize == 0 && interSize ==0) {
        return 65536;
    } else {
    answer = 65536*interSize/uniSize;
    return answer;
    }
}
int main(){
    cout << solution("FRANCE", "french") << endl;
    return 0;
}