#include <iostream>
#include <algorithm>
using namespace std;
int l,c;
char a[17], p[17];
bool isVowel[26];
void backtrack(int pos, int prev, int consonant, int vowel){
    if(pos == l) {
        if(consonant >= 2 && vowel >= 1) puts(p);
        return;
    }
    for(int i=prev+1;i<c;i++){
        p[pos] = a[i];
        backtrack(pos+1, i, consonant + !isVowel[a[i]-'a'], vowel + isVowel[a[i]-'a']);
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> l >> c;
    for(int i=0;i<c;i++){
        cin >> a[i];
    }
    sort(a, a+c);
    //알파벳순으로 정렬
    isVowel[0] = isVowel[4] = isVowel[8] = isVowel[14] = isVowel[20] = true;
    //모음 체크
    backtrack(0,-1,0,0);
    return 0;
}