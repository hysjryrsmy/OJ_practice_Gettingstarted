#define _CRT_SECURE_NO_WARING
#include <iostream>
#include <algorithm>
#include<cstdio>
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
	for (int i = 0; i < n; i++) {
		scanf_s("%d", &wm[i].num);
		wm[i].ind = i + 1;
	}
	sort(wm, wm + n, cmp);
	for (int i = 0; i < m; i++) {
		int t, l = 0, r = n - 1;
		scanf_s("%d", &t);
		while (l <= r) {
			int mid = (l + r) / 2;
			if (wm[mid].num == t) {
				printf("%d\n", wm[mid].ind);
				break;
			}
			if (wm[mid].num < t) {
				l = mid + 1;
			}
			else {
				r = mid - 1;
			}
		}
		if (l > r) {
			printf("0\n");
		}
	}
	return 0;
}
