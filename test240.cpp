#define _CRT_SECURE_NO_WARING

#include <iostream>
using namespace std;


int num[8] = { 0,1,3,9,27,81,243,729 };
char mmap[1005][1005];


void func(int x, int y, int cnt) {
	if (cnt == 1) {
		mmap[x][y] = 'X';
		return ;
	}
	func(x, y, cnt - 1);
	func(x, y + num[cnt] / 3 * 2, cnt - 1);
	func(x + num[cnt] / 3 * 2, y, cnt - 1);
	func(x + num[cnt] / 3, y + num[cnt] / 3, cnt - 1);
	func(x + num[cnt] / 3 * 2, y + num[cnt] / 3 * 2, cnt - 1);

}

int main() {
	func(1, 1, 7);
	int n;
	while (cin >> n) {
		if (n == -1) {
			break;
		}
		for (int i = 1; i <= num[n]; i++) {
			for (int j = 1; j <= num[n]; j++) {
				if (mmap[i][j] == 'X') {
					cout << 'X';
				}
				else {
					cout << ' ';
				}
			}
			cout << endl;
		}
		cout << '-' << endl;
	}

	return 0; 
}
