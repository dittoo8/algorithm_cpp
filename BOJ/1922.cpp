#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 10001
using namespace std;
struct adj{
    int x, y, c;
};
bool cmp(adj a, adj b){
    if (a.c < b.c) return true;
    else return false;
}
int v,e;
vector<adj> a;
int parent[MAX];
int getP(int x){
    if (parent[x] == x) return x;
    else {
        int y = getP(parent[x]);
        parent[x] = y;
        return y;
    }
}
void unionP(int x, int y){
    x = getP(x);
    y = getP(y);
    if (x > y ){
        parent[x] = y;
    }else {
        parent[y] = x;
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> v >> e;
    int v1,v2,n,c,cost=0;
    for(int i=1;i<=v;i++){
        parent[i] = i;
    }
    for(int i=0;i<e;i++){
        cin >> v1 >> v2 >> c;
        a.push_back({v1,v2,c});
    }
    sort(a.begin(),a.end(), cmp);
    for(int i=0;i<(int)a.size();i++){
        int x = getP(a[i].x);
        int y = getP(a[i].y);
        if (x==y) continue;
        unionP(x, y);
        cost+=a[i].c;
        n++;
        if (n == v-1) break;
    }
    cout << cost << '\n';
    return 0;
}