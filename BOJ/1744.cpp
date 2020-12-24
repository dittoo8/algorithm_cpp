#include <iostream>
#include <queue>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n,ans = 0,x;
    priority_queue<int> mnq, mxq;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> x;
        if(x==1) ans+=1;
        else if (x>0){
            mxq.push(x);
        }else {
            mnq.push(-x);
        }
    }
    while(!mnq.empty()){
        int t1 = mnq.top();
        mnq.pop();
        if(mnq.empty()){
            ans-=t1;
            break;
        }else {
            int t2 = mnq.top();
            mnq.pop();
            ans+=t1*t2;
        }
    }
    while(!mxq.empty()){
        int t1 = mxq.top();
        mxq.pop();
        if(mxq.empty()){
            ans+=t1;
            break;
        }else {
            int t2 = mxq.top();
            mxq.pop();
            ans+=t1*t2;
        }
    }
    cout << ans << '\n';
    return 0;
}