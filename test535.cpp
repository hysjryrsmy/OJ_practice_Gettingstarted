#define _CRT_SECURE_NO_WARING

#include <iostream>
using namespace std;

int h, w, sx, sy, ans = 1;
char mmap[55][55];

int dir[4][2] = {
	0,1,  //éÓ
	1,0,  //ù»
	0,-1, //ñ§
	-1,0  //ß¾
};

void func(int x0, int y0) {
	for (int i = 0; i < 4; i++) {
		int x = x0 + dir[i][0];
		int y = y0 + dir[i][1];
		if (mmap[x][y] == '.') {
			ans++;
			mmap[x][y] = '#';
			func(x, y);
		}
	}
}


int main() {
	cin >> h >> w;
	for (int i = 1; i <= w; i++) {
		for (int j = 1; j <= h; j++) {
			cin >> mmap[i][j];
			if (mmap[i][j] == '@') {
				sx = i;
				sy = j;
			}
		}
	}
	func(sx, sy);
	cout << ans << endl;

	return 0;
}