#define _CRT_SECURE_NO_WARING

#include <iostream>
using namespace std;


int n, m, ans;
char mmap[2005][2005];
int dir[8][2] = {
	1,0,
	0,1,
	-1,0,
	0,-1,
	1,1,
	-1,-1,
	1,-1,
	-1,1
};

void func(int x0, int y0) {
	for (int i = 0; i < 8; i++) {
		int x = x0 + dir[i][0];
		int y = y0 + dir[i][1];
		if (mmap[x][y] == '#') {
			mmap[x][y] = 0;
			func(x, y);
		}
	}
}


int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> mmap[i][j];
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (mmap[i][j] == '#') {
				ans++;
				mmap[i][j] = 0;
				func(i, j);
			}
		}
	}

	cout << ans << endl;

	return 0;
}