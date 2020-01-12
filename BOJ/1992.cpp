#include <cstdio>
using namespace std;
int n;
char a[65][65];

void solve(int x, int y, int len) {
	char temp = a[y][x];
	if (len==1) {
		printf("%c", temp);
		return;
	}
	for (int i = y; i < y+len; ++i) {
		for (int j = x; j < x+len; ++j) {
			if (temp != a[i][j]) {
				printf("(");
				solve(x,y,len/2);
                solve(x+len/2,y,len/2);
                solve(x,y+len/2,len/2);
                solve(x+len/2,y+len/2,len/2);
				printf(")");
				return;
			}
		}
	}
	printf("%c", temp);
}

int main() {
	scanf("%d\n", &n);
	for (int i = 0; i < n; ++i)
		scanf("%s", a[i]);
	solve(0, 0, n);

	return 0;
}