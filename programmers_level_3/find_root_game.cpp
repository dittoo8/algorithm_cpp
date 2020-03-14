#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
typedef struct Node{
    int idx,x,y;
    struct Node *left;
    struct Node *right;
}Node;
vector<int> pre,post;
bool cmp(Node &a, Node &b){
    if(a.y == b.y){
        return a.x < b.x;
    }
    return a.y > b.y;
}
void insertNode(Node *parent, Node *child){
    if(parent->x > child -> x){
        if(parent->left==NULL)
            parent->left=child;
        else insertNode(parent->left,child);
    }else {
        if(parent->right == NULL)
            parent->right=child;
        else insertNode(parent->right,child);
    }
}
void postOrder(Node *root){
    if(root){
        postOrder(root->left);
        postOrder(root->right);
        post.push_back(root->idx);
    }
}
void preOrder(Node *root){
    if(root){
        pre.push_back(root->idx);
        preOrder(root->left);
        preOrder(root->right);
    }
}
vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer;
    int n = nodeinfo.size();
    vector<Node> nodes;
    for(int i=0;i<n;i++){
        nodes.push_back({i+1,nodeinfo[i][0],nodeinfo[i][1]});
    }
    sort(nodes.begin(),nodes.end(),cmp);
    Node *root = &nodes[0];
    for(int i=1;i<n;i++){
        insertNode(root,&nodes[i]);
    }
    preOrder(root);
    postOrder(root);
    answer.push_back(pre);
    answer.push_back(post);
    return answer;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector<vector<int > > v;
    vector<int> v1;
    v1.push_back(5);
    v1.push_back(3);
    vector<int> v2;
    v2.push_back(11);
    v2.push_back(5);
    vector<int> v3;
    v3.push_back(13);
    v3.push_back(3);
    vector<int> v4;
    v4.push_back(3);
    v4.push_back(5);
    vector<int> v5;
    v5.push_back(6);
    v5.push_back(1);
    vector<int> v6;
    v6.push_back(1);
    v6.push_back(3);
    vector<int> v7;
    v7.push_back(8);
    v7.push_back(6);
    vector<int> v8;
    v8.push_back(7);
    v8.push_back(2);
    vector<int> v9;
    v9.push_back(2);
    v9.push_back(2);
    v.push_back(v1);
    v.push_back(v2);
    v.push_back(v3);
    v.push_back(v4);
    v.push_back(v5);
    v.push_back(v6);
    v.push_back(v7);
    v.push_back(v8);
    v.push_back(v9);
    vector<vector<int> > res = solution(v);
    for(int i=0;i<2;i++){
        for(int j=0;j<res[i].size();j++){
            cout <<res[i][j];
        }
        cout <<endl;
    }
    return 0;
}