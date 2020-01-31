#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int dfs(int x, int y,int m, int n, vector<vector<int> > picture, bool check[102][102]) {
    int dx[] = {-1,0,0,1}, dy[] = {0,-1,1,0};
    int cnt = 1;
    check[x][y] = 1;
    for(int i=0;i<4;i++){
        int nx = x + dx[i], ny = y + dy[i];
        if (nx<0 || nx >=m || ny <0 || ny >= n) continue;
        if(picture[nx][ny] == picture[x][y] && !check[nx][ny]){
            check[nx][ny] = 1;
            cnt += dfs(nx,ny,m,n,picture, check);
        }
    }
    return cnt;
}
void solution(int m, int n, vector<vector<int> > picture) {
    bool check[102][102] = {0,};
    int cnt = 0;
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(picture[i][j]!=0 && !check[i][j]) {
                number_of_area++;
                cnt = dfs(i,j,m,n,picture,check);
                max_size_of_one_area = max(cnt,max_size_of_one_area);
                cnt = 0;
            }
        }
    }
    
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    // return answer;
    cout << answer[0] << endl;
    cout << answer[1] << endl;
}
int main(){
    vector<vector<int> > picture;
    vector<int> picture1;
    vector<int> picture2;
    vector<int> picture3;
    vector<int> picture4;
    vector<int> picture5;
    vector<int> picture6;

    picture1.push_back(1);
    picture1.push_back(1);
    picture1.push_back(1);
    picture1.push_back(0);

    picture2.push_back(1);
    picture2.push_back(2);
    picture2.push_back(2);
    picture2.push_back(0);

    picture3.push_back(1);
    picture3.push_back(0);
    picture3.push_back(0);
    picture3.push_back(1);

    picture4.push_back(0);
    picture4.push_back(0);
    picture4.push_back(0);
    picture4.push_back(1);

    picture5.push_back(0);
    picture5.push_back(0);
    picture5.push_back(0);
    picture5.push_back(3);
    
    picture6.push_back(0);
    picture6.push_back(0);
    picture6.push_back(0);
    picture6.push_back(3);
    picture.push_back(picture1);
    picture.push_back(picture2);
    picture.push_back(picture3);
    picture.push_back(picture4);
    picture.push_back(picture5);
    picture.push_back(picture6);
    solution(6,4, picture);
    return 0;
}