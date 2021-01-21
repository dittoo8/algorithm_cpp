#include <iostream>
#include <queue>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    queue<int> q;
    for(int i=0;i<n;i++){
        string commend;
        cin >> commend;
        if(commend == "push"){
            int x;
            cin >> x;
            q.push(x);
        }else if (commend == "pop"){
            if(q.size()==0){
                cout << -1 << '\n';
            }else {
                cout << q.front() << '\n';
                q.pop();
            }
            
        }else if (commend == "size"){
            cout << q.size() << '\n';
        }else if (commend == "empty"){
            if(q.empty()){
                cout << 1 << '\n';
            }else {
                cout << 0 << '\n';
            }
        }else if (commend == "front"){
            if(q.size()==0){
                cout << -1 << '\n';
            }else {
                cout << q.front() << '\n';
            }
            
        }else if (commend == "back"){
            if(q.size()==0){
                cout << -1 << '\n';
            }else {
                cout << q.back() << '\n';
            }
        }
    }
    return 0;
}