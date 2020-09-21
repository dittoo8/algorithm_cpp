#include <iostream>
#include <algorithm>
#define MAX 100001
using namespace std;
int n,a[MAX];
int histogram(int s, int e){
    if (s ==e) return 0;
    if(s+1 == e) return a[s];
    int mid = (s+e)/2;
    int result = max(histogram(s,mid),histogram(mid+1,e));
    int w = 1, h = a[mid], l=mid,r = mid;
    while(r-l+1 < e-s){
        int p = l > s ? min(h,a[l-1]) : -1;
        int q = r < e-1 ? min(h,a[r+1]) : -1;
        if (p >=q){
            h = p;
            l--;
        }else {
            h = q;
            r++;
        }
        result = max(result , ++w*h);
    }
    return result;

}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    cout << histogram(0,n) << '\n';
    return 0;
}