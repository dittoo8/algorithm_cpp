#include <string>
#include <vector>
#include <cstdio>
#include <bitset>
#include <iostream>
using namespace std;
bool map[17][17];
void solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer(n);
    string temp1, temp2;
    for(int i=0;i<n;i++){
        temp1 = (bitset<16>(arr1[i]) | bitset<16>(arr2[i])).to_string();
        //비트 OR 연산
        temp2 = "";
        // cout << temp1 << end;
        for(int j= 16- n;j<16;j++){
            if(temp1[j] == '1') temp2 += "#";
            else temp2 += " ";
        }
        answer[i] = temp2;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%c",answer[i][j]);
        }
        printf("\n");
    }
}
int main(){
    vector<int> arr1;
    vector<int> arr2;
    // arr1.push_back(9);
    // arr1.push_back(20);
    // arr1.push_back(28);
    // arr1.push_back(18);
    // arr1.push_back(11);
    // arr2.push_back(30);
    // arr2.push_back(1);
    // arr2.push_back(21);
    // arr2.push_back(17);
    // arr2.push_back(28);
    arr1.push_back(46);
    arr1.push_back(33);
    arr1.push_back(33);
    arr1.push_back(22);
    arr1.push_back(31);
    arr1.push_back(50);
    arr2.push_back(27);
    arr2.push_back(56);
    arr2.push_back(19);
    arr2.push_back(14);
    arr2.push_back(14);
    arr2.push_back(10);
    solution(6, arr1, arr2);
    return 0;
}