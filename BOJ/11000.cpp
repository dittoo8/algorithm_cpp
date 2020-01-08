/*
수강신청의 마스터 김종혜 선생님에게 새로운 과제가 주어졌다. 

김종혜 선생님한테는 Si에 시작해서 Ti에 끝나는 N개의 수업이 주어지는데, 최소의 강의실을 사용해서 모든 수업을 가능하게 해야 한다. 

참고로, 수업이 끝난 직후에 다음 수업을 시작할 수 있다. (즉, Ti ≤ Sj 일 경우 i 수업과 j 수업은 같이 들을 수 있다.)

수강신청 대충한 게 찔리면, 선생님을 도와드리자!
*/
#include <cstdio>
#include <algorithm>
#include<queue>
#include <iostream>
using namespace std;
int main(){
    priority_queue<int, vector<int>, greater<int> > room;
    int n;
    scanf("%d", &n);
    pair<int, int> lec[n];
    for(int i=0;i<n;i++){
        scanf("%d %d", &lec[i].first, &lec[i].second);
    }
    sort(lec,lec+n);
    room.push(lec[0].second);
    //첫번째로 시작하는 수업 끝나는 시간 먼저 추가

    //첫번째 수업은 끝나는 시간 추가했으니까 i=1부터 시작
    for(int i=1;i<n;i++){
        if(room.top()>lec[i].first) {
            room.push(lec[i].second);
        } else {
            room.pop();
            room.push(lec[i].second);
        }
    }


    cout<<room.size()<<endl;
    
}