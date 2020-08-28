#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct node {
    int parent, left,  right;
};
struct level {
    int mn = 1000000,mx= 0;
};
int order =  0, max_depth;
vector<node> trees;
vector<level> levels;
int find_root(){
    for(int i=1;i<trees.size();i++){
        if(trees[i].parent==0) return i;
    }
    return 0;
}
void dfs_inorder(int n, int depth){ //중위순회
    if (n==-1) return;
    // cout << "n : " << n << ", depth : " <<  depth << endl;
    dfs_inorder(trees[n].left,depth+1);
    order++;
    // cout  << "order : " << order << endl;
    levels[depth].mn = min(levels[depth].mn,order);
    levels[depth].mx = max(levels[depth].mx,order);
    // cout << "levels[" << depth <<"] min :" << levels[depth].mn <<", max : " <<levels[depth].mx <<endl;
    max_depth = max(max_depth , depth);
    // cout  << "max depth : " << max_depth << endl;
    dfs_inorder(trees[n].right,depth+1);
}
pair<int, int> get_max(){
    int max_level=0, max_width =0;
    for(int i=1;i<=max_depth;i++){
        int width = levels[i].mx - levels[i].mn +1;
        if (max_width < width){
            max_width = width;
            max_level = i;
        }
    }
    return make_pair(max_level,max_width);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    trees.resize(n+1);
    for(int i=0;i<n;i++){
        int p,l,r;
        cin >> p >> l  >> r;
        trees[p].left = l;
        trees[p].right = r;
        if (l!=-1){
            trees[l].parent = p;
        }
        if (r!=-1){
            trees[r].parent = p;
        }
    }
    levels.resize(n+1);
    dfs_inorder(find_root(),1);
    pair<int, int> max_p = get_max();
    cout << max_p.first <<' '<<max_p.second << '\n';
    return  0;
}