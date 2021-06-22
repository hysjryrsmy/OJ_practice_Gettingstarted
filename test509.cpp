#define _CRT_SECURE_NO_WARING

#include <iostream>
#include <algorithm>
using namespace std;

struct task {
	int t, m;
};

bool cmp(task a, task b) {
	if (a.m == b.m)  return a.t < b.t;
	return a.m > b.m;
}

int n, m, mark[100000] = { 1 };
task game[505];

int main() {
	cin >> m >> n;
	for (int i = 0; i < n; i++) {
		cin >> game[i].t;
	}
	for (int i = 0; i < n; i++) {
		cin >> game[i].m;
	}
	sort(game, game + n, cmp);
	for (int i = 0; i < n; i++) {
		for (int j = game[i].t; j >= 0; j--) {
			if (mark[j] == 0) {
				mark[j] = 1;
				break;
			}
			if (j == 0) {
				m -= game[i].m;
			}
		}
	}

	cout << m << endl;

	return 0;
}