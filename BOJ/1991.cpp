#include <cstdio>
using namespace std;
char bTree[27][2];
int n;
void pre(int x){
    printf("%c",x+'A');
    if(bTree[x][0]!='.'){
        pre(bTree[x][0]-'A');
    }
    if(bTree[x][1]!='.'){
        pre(bTree[x][1]-'A');
    }
}
void in(int x){
    if(bTree[x][0]!='.') {
        in(bTree[x][0]-'A');
    } 
    printf("%c",x+'A');
    if(bTree[x][1]!='.') {
        in(bTree[x][1]-'A');
    }
}
void post(int x){
    if(bTree[x][0]!='.'){
        post(bTree[x][0]-'A');
    }
    if(bTree[x][1]!='.'){
        post(bTree[x][1]-'A');
    }
    printf("%c", x+'A');

}
int main(){
    scanf("%d%*c", &n);
    for(int i=0;i<n;i++){
        char temp1,temp2,temp3;
        scanf("%c%*c%c%*c%c%*c", &temp1, &temp2, &temp3);
        bTree[temp1-'A'][0] = temp2; 
        bTree[temp1-'A'][1] = temp3; 
    }
    pre(0);
    printf("\n");
    in(0);
    printf("\n");
    post(0);
    printf("\n");
    return 0;
}