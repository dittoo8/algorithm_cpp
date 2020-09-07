#include <iostream>
#include <algorithm>
using namespace std;
int heap[100001];
int lastIdx;
void pop() {
    if (lastIdx == 0){
        cout << 0 << '\n';
        return;
    }
    cout << heap[1] << '\n';
    heap[1] = heap[lastIdx];
    heap[lastIdx--] = 0;
    for (int i=1; i*2 <= lastIdx;) {
        if (heap[i] > heap[i*2] && heap[i] > heap[i*2+1]) {
            break;
        } else if (heap[i*2] > heap[i*2+1]) {
            swap(heap[i], heap[i*2]);
            i = i*2;
        } else {
            swap(heap[i], heap[i*2+1]);
            i = i*2+1;
        }
    }
}
void push(int x) {
    heap[++lastIdx] = x;
    for (int i=lastIdx; i>1; i/=2) {
        if (heap[i/2] < heap[i]) {
            swap(heap[i/2],heap[i]);
        } else break;
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t,x;
    cin >> t;
    while (t--) {
        int x;
        cin >> x;
        if (x) push(x);
        else pop();
    }
    return 0;
}