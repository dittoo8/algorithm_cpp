#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int N;
	cin >> N;
    int cnt_2 = 0, cnt_5 = 0; // 2의 개수, 5의 개수
	// 1, 2, ..., n - 1, n에 대한 모든 경우 검사
	for (int i = 1; i <= N; i++) {
        int x = i,div; 
		while (true) {
			if (x % 2 == 0 && x % 5 == 0) {
				cnt_2++, cnt_5++;
                div = 10;
			}else if (x % 2 == 0) {
                cnt_2++;
                div = 2;
			}else if (x % 5 == 0) {
				cnt_5++;
                div = 5;
			}else break;
            x/=div;
		}
	}
	if(cnt_2 >= cnt_5){
        cout << cnt_5 << '\n';
    }else cout << cnt_2 << '\n';

	return 0;
}