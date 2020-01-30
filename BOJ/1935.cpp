#include <iostream>
#include <cstdio>
#include <stack>
#include <string>
using namespace std;
int n;
int num[102];
string input;
stack<double> st;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    cin >> input;
    for(int i=0;i<n;i++){
        cin >> num[i] ;
    }
    for(int i= 0;i<input.length();i++){
        if(input[i] >= 'A' && input[i] <= 'Z'){
            st.push(num[input[i]-'A']);
        } else {
            double a = st.top();
            st.pop();
            double b = st.top();
            st.pop();
            double res;
            if (input[i] == '*'){
                res = b*a;
            } else if (input[i] == '/'){
                res = b/a;
            } else if (input[i] == '+'){
                res = b+a;
            }else if (input[i] == '-'){
                res = b-a;
            }
            st.push(res);
        }
    }

    printf("%.2f", st.top());
    return 0;
}