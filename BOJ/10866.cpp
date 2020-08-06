#include <iostream>
#include <string>
using namespace std;
int dq[20001];
int n, l=10000,h=10000,cnt;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    while(n--){
        string str;
        cin >> str;
        if (str == "push_back"){
            int num;
            cin >> num;
            dq[h++]=num;
            cnt++;
        }else  if (str ==  "push_front"){
            int num;
            cin >> num;
            dq[--l]= num;
            cnt++;
        }else if (str == "pop_front"){
            if (cnt ==0){
                cout << -1 << '\n';
            }else {
                cout << dq[l++] << '\n';
                cnt--;
            }
        }else if (str ==  "pop_back"){
            if (cnt ==0){
                cout << -1 << '\n';
            }else {
                cout << dq[--h] << '\n';
                cnt--;
            }
        }else if (str == "size"){
            cout << cnt << '\n';
        }else  if (str =="empty"){
            if (cnt == 0){
                cout << 1 << '\n';
            }else cout << 0 << '\n';
        }else if (str == "front"){
            if (cnt ==0){
                cout << -1 << '\n';
            }else cout << dq[l] << '\n';
        
        }else if (str == "back"){
            if (cnt ==0){
                cout << -1 << '\n';
            }else cout << dq[h-1] << '\n';
        }
    }
    return 0;
}