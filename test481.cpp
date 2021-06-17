#define _CRT_SECURE_NO_WARING

#include <iostream>
#include <algorithm>
using namespace std;

int r, ans[15][2];

void print(int cnt) {
	int s1 = 0, s2 = 0;
	for (int i = 1; i <= cnt; i++) {
		cout << ans[i][0] << ":" << ans[i][1] << endl;
		s1 += ans[i][0];
		s2 += ans[i][1];
	}
	cout << s1 << ":" << s2 << endl;
}

int main() {
	cin >> r;
	for (int i = 1; i <= 10; i++) {
		int n1[10], n2[10];
		for (int j = 0; j < 8; j++) {
			cin >> n1[j];
			if (n1[j] == -1) {
				print(i - 1);
				return 0;
			}
		}
		for (int j = 0; j < 8; j++) {
			cin >> n2[j];
		}
		sort(n1, n1 + 8);
		sort(n2, n2 + 8);
		if (n1[0] < n2[0]) {
			for (int j = 0; j < 8; j++) {
				if (n1[j] < n2[0] && n1[j] <= r) {
					ans[i][0]++;
				}
				else {
					break;
				}
			}
		}
		else {
			for (int j = 0; j < 8; j++) {
				if (n2[j] < n1[0] && n2[j] <= r) {
					ans[i][1]++;
				}
				else {
					break;
				}
			}
		}
	}
	print(10);
	return 0;
}
