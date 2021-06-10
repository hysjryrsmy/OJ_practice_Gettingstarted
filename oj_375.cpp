#define _CRT_SECURE_NO_WARING
#include <iostream>
#include <algorithm>
using namespace std;

struct node {
	int c, m, e, sum, num;
};

node stu[305];
int n;

bool cmp(const node& a, const node& b) {
	if (a.sum == b.sum) {
		if (a.c == b.c) {
			return a.num < b.num;
		}
		return a.c > b.c;
	}
	return a.sum > b.sum;
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> stu[i].c >> stu[i].m >> stu[i].e;
		stu[i].sum = stu[i].c + stu[i].m + stu[i].e;
		stu[i].num = i;
	}
	sort(stu + 1, stu + n + 1, cmp);
	for (int i = 1; i < 6; i++) {
		cout << stu[i].num << " " << stu[i].sum << endl;
	}
	return 0;
}