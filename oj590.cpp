
#define _CRT_SECURE_NO_WARING
#include <iostream>
using namespace std;

//树塔狂想曲

int n, m, num[1005][1005], utd[1005][1005], dtu[1005][1005], ans[1005][1005], mmax[1005], ind[1005], sec[1005];
//最大值mmax[1005], 最大坐标ind[1005], 次大值sec[1005]

int main() {

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			cin >> num[i][j];
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			utd[i][j] = max(utd[i - 1][j - 1], utd[i - 1][j]) + num[i][j]; //从上往下求
		}
	}
	for (int i = n; i > 0; i--) {
		for (int j = 1; j <= i; j++) {
			dtu[i][j] = max(dtu[i + 1][j], dtu[i + 1][j + 1]) + num[i][j];//从下往上求
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			ans[i][j] = utd[i][j] + dtu[i][j] - num[i][j]; //
		}
	}
	for (int i = 2; i <= n; i++) {
		int m1 = 0, cnt = 0, m2 = 0;
		for (int j = 1; j <= i; j++) {
			if (m1 < ans[i][j]) {
				m2 = m1;
				m1 = ans[i][j];
				cnt = j;
			}
			else if (m2 < ans[i][j]) {
				m2 = ans[i][j];
			}
		}
		mmax[i] = m1;
		ind[i] = cnt;
		sec[i] = m2;
	}
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		if (a == 1 && b == 1) {
			cout << -1 << endl;
		}
		else if (ind[a] == b) {
			cout << sec[a] << endl;
		}
		else {
			cout << mmax[a] << endl;
		}
	}
	return 0;
}