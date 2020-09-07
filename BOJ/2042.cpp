#include <iostream>
#define MAX 1000001
using namespace std;
int n,m,k;
long long a[MAX];
long long segment_tree[MAX*4];
long long make_segment(int start, int end, int node){
    if (start == end) return segment_tree[node] = a[start];
    int mid = (start+end) / 2;
    return segment_tree[node] = make_segment(start,mid,node*2) + make_segment(mid+1, end,node*2+1);
}
long long sum(int start, int end, int node ,int left ,int right){
    if (left > end || right < start) return 0;
    if (left <= start && end <= right) return segment_tree[node];
    int mid = (start+end)/2;
    return sum(start,mid,node*2,left,right) + sum(mid+1,end,node*2+1,left,right);
}
void update_val(int start, int end, int node ,int idx ,int val){
    if (idx < start || idx > end) return;
    segment_tree[node]+=val;
    if (start == end) return;
    int mid = (start + end) / 2;
    update_val(start, mid , node*2,idx, val);
    update_val(mid+1,end,node*2+1, idx,val);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m >> k;
    int op, b, c;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    make_segment(0,n-1,1);
    for(int i=0;i<m+k;i++){
        cin >> op >> b >> c;
        if (op ==1){ //change
            update_val(0,n-1,1,b-1,c-a[b-1]);
            a[b-1] = c;
        }else { // print sum
            cout << sum(0,n-1,1,b-1,c-1) << '\n';
        }
    }
    return 0;
}