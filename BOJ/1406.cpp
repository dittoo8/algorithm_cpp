#include <stdio.h>
#include <list>
using namespace std;

char s[100001];
int n;
list<char> str;
list<char>::iterator it;
int main() {
    scanf("%s", s);
    scanf("%d", &n);
    for(int i=0; s[i]; i++)
        str.push_back(s[i]);
    it = str.end();
    char com, alp;
    while(n--) {
        scanf(" %c", &com);
        if(com == 'L' && it != str.begin()) it--;
        else if(com == 'D' && it != str.end()) it++;
        else if(com == 'B' && it != str.begin()) it--, it = str.erase(it);
        else if(com == 'P') {
            scanf(" %c", &alp);
            str.insert(it, alp);
        }
    }
    for(it = str.begin(); it != str.end(); it++)
        printf("%c", *it);
    return 0;
}