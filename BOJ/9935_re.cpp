#include <iostream>
#include <stack>
#include <string>
#define MAX 1000001
using namespace std;
bool erased[MAX];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    string str, bomb;
    cin >> str >> bomb;
    if (bomb.length()==1){
        for(int i=0;i<str.length();i++){
            if (str[i]==bomb[0]) erased[i]=true;
        }
    }else {
        stack<pair<int, int> > st;
        for(int i=0;i<str.length();i++){
            if(str[i]==bomb[0]){
                st.push(make_pair(i,0));
            }else {
                if (!st.empty()){
                    int strIdx = st.top().first;
                    int bombIdx = st.top().second;
                    if (str[i]==bomb[bombIdx+1]){
                        st.push(make_pair(i,bombIdx+1));
                        if (bombIdx+1 == bomb.length()-1){
                            for(int k=0;k<bomb.length();k++){
                                erased[st.top().first] = true;
                                st.pop();
                            }
                        }
                    }else {
                        while(!st.empty()){
                            st.pop();
                        }
                    }
                }
            }
        }
    }
    bool printed = false;
    for(int i=0;i<str.length();i++){
        if (erased[i]) continue;
        cout << str[i];
        printed = true;
    }
    if (!printed) cout << "FRULA" << '\n';
    return 0;
}