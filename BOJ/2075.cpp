#include <iostream>
#include <queue>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,x;
    cin >> n;
    priority_queue<int> pq;
    for(int i=0;i<n*n;i++){
        cin >> x;
        if (pq.size()<n) pq.push(-x);
        else {
            if (-pq.top() < x){
                pq.pop();
                pq.push(-x);
            }else continue;
        }
    }
    cout << -pq.top() << '\n';
    return 0;
}