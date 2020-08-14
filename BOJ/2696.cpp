#include <iostream>
#include <queue>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int> > minHeap;
    int tc,m,num,count;
    cin >> tc;
    while(tc--){
        while(!maxHeap.empty()) maxHeap.pop();
        while(!minHeap.empty()) minHeap.pop();
        cin >> m;
        cout << m/2+1 <<'\n';
        count = 0;
        for(int i=1;i<=m;i++){
            cin >> num;
            if (maxHeap.size() == minHeap.size()){
                maxHeap.push(num);
            }else minHeap.push(num);
            if(minHeap.size() && maxHeap.size() && minHeap.top()< maxHeap.top()){
                int a = maxHeap.top(); maxHeap.pop();
                int b = minHeap.top(); minHeap.pop();
                minHeap.push(a) ; maxHeap.push(b);
            }
            if (i%2){
                cout << maxHeap.top() << ' ';
                count++;
                if (count%10 == 0) cout  << '\n';
            }
        }
        cout << '\n';
    }
    return 0;
}