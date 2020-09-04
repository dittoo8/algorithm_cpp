#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int> > minHeap;
    int n,num;
    cin >> n;
    while(n--){
        cin >> num;
        if (maxHeap.size() == minHeap.size()){
            maxHeap.push(num);
        } else minHeap.push(num);
        if(!minHeap.empty() && !maxHeap.empty() && minHeap.top()< maxHeap.top()){
            int a = maxHeap.top(); maxHeap.pop();
            int b = minHeap.top(); minHeap.pop();
            minHeap.push(a) ; maxHeap.push(b);
        }
        cout << maxHeap.top() << '\n';
    }
    return 0;
}