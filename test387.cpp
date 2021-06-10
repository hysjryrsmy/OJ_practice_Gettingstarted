#define _CRT_SECURE_NO_WARING

#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

struct node {
	int ind, num;
};

node wm[100005];
int n, m;

bool cmp(const node& a, const node& b) {
	return a.num < b.num;
}

int main() {
	scanf_s("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf_s("%d", &wm[i].num);
		wm[i].ind = i;
	}
	wm[0].ind = 0;
	wm[0].num = 2000000000;
	sort(wm, wm + n + 1, cmp);
	for (int i = 0; i < m; i++) {
		int t, l = 0, r = n;
		scanf_s("%d", &t);
		while (l != r) {
			int mid = (l + r) / 2;
			if (wm[mid].num >= t) {
				r = mid;
			}
			else {
				l = mid + 1;
			}
		}
		printf("%d\n", wm[l].ind);
	}



	return 0;
}