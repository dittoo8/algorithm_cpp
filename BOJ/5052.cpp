#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAX = 10;

struct Trie {
    Trie* go[MAX];
    bool output;
    bool goexist;

    Trie(){
        fill(go,go+MAX, nullptr);
        output = goexist =false;
    }
    ~Trie(){
        for(int i=0;i<MAX;i++){
            if(go[i]) delete go[i];
        }
    }
    void insert(const char* key){
        if(*key == '\0') output =true;
        else {
            int next = *key - '0';
            if(!go[next]) go[next] = new Trie;
            goexist = true;
            go[next]->insert(key+1);
        }
    }
    bool consistent(){
        if(goexist && output) return false;
        for(int i=0;i<MAX;i++){
            if(go[i] && !go[i]->consistent()) return false;
        }
        return true;
    }
};
int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int n;
        scanf("%d", &n);
        Trie *root = new Trie;
        for(int i=0;i<n;i++){
            char tel[11];
            scanf("%s",tel);
            root->insert(tel);
        }
        puts(root->consistent() ? "YES":"NO");
        delete root;
    }
}