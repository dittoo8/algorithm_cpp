#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    for(int i=0;i<phone_book.size();i++){
        for(int j=0;j<phone_book.size();j++){
            if(i!=j && phone_book[j].find(phone_book[i])==0){
                answer = false;
                return answer;
            }
        }
    }
    return answer;
}
int main(){
    vector<string> v;
    v.push_back("119");
    v.push_back("97674223");
    v.push_back("1195524421");
    bool result =  solution(v);
    if (result){
        cout << "true" << endl;
    } else {
        cout << "false" <<endl;
    }
    return 0;
}