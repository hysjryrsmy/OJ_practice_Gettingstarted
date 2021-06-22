#define _CRT_SECURE_NO_WARING

#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

struct node {
	int t, ind;
};

int n, sum, now;
node stu[35];

bool cmp(const node& a, const node& b) {
	return a.t < b.t;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> stu[i].t;
		stu[i].ind = i + 1;
	}
	sort(stu, stu + n, cmp);
	for (int i = 0; i < n; i++) {
		if (i) cout << " ";
		cout << stu[i].ind;
		sum += now;
		now += stu[i].t;
	}

	cout << endl;
	printf("%.2f\n", (double)sum / n);

	return 0;
}