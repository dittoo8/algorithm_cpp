#include <iostream>
#include <deque>
#include <string>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    deque<int> dq;
    int tc,n;
    cin >> tc;
    while(tc--){
        dq.clear();
        string ops,str;
        cin >> ops >> n >> str;
        int num = 0;
        if(n !=0){
            for(int i=1;i<str.length();i++){
                if (str[i]== ',' || str[i]==']'){
                    dq.push_back(num);
                    num = 0;
                }else {
                    if (num != 0) num*=10;
                    num+= str[i]-'0';
                }
            }
        }
        bool errorCk = false;
        int dir = 1;
        for(int i=0;i<ops.length();i++){
            if (ops[i]=='R') dir*= -1;
            else {
                if (dq.empty()) {
                    errorCk = true;
                    cout << "error" << '\n';
                    break;
                }
                if (dir == -1) dq.pop_back();
                else dq.pop_front();
            }
        }
        if(errorCk) continue;
        cout << "[" ;
        if (dq.empty()) {
            cout << "]" << '\n';
			continue;
		}
		if (dir == 1) {
			for (int i = 0; i < dq.size() - 1; i++) {
                cout << dq[i] <<"," ;
			}
            cout << dq[dq.size()-1] <<"]" << '\n';
		}else {
			for (int i = dq.size() - 1; i > 0; i--) {
                cout << dq[i] <<"," ;
			}
			cout << dq[0] <<"]" << '\n';
		}
    }
    return 0;
}