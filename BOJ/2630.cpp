#include <iostream>
using namespace std;
int N, answer[2];
bool paper[128][128];
void divide_paper(int x, int y, int size){
	for (int i = x; i < x + size; i++){
		for (int j = y; j < y + size; j++){
			if (paper[x][y] != paper[i][j]){
				int s = size / 2;
				divide_paper(x, y, s);
				divide_paper(x + s, y, s);
				divide_paper(x, y + s, s);
				divide_paper(x + s, y + s, s);
				return;
			}
		}
	}
	answer[paper[x][y]]++;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            cin >> paper[i][j];
        }
    }
	divide_paper(0, 0, N);
    cout << answer[0] << '\n';
    cout << answer[1] << '\n';
	return 0;
}
