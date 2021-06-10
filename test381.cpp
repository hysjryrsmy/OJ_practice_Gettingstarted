#define _CRT_SECURE_NO_WARING
#include <iostream>
#include <algorithm>
using namespace std;

struct node {
	char name[22], off, west;
	int avg, cla, paper, num, sum;
};

node stu[105];
int n, ans;

int func(int x) {
	int t = 0;
	if (stu[x].avg > 80 && stu[x].paper > 0) t += 8000;
	if (stu[x].avg > 85 && stu[x].cla > 80) t += 4000;
	if (stu[x].avg > 90) t += 2000;
	if (stu[x].avg > 85 && stu[x].west == 'Y') t += 1000;
	if (stu[x].cla > 80 && stu[x].off == 'Y') t += 850;
	return t;
}

bool cmp(const node& a, const node& b) {
	if (a.sum == b.sum) {
		return a.num < b.num;
	}
	return a.sum > b.sum;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> stu[i].name >> stu[i].avg >> stu[i].cla >> stu[i].off >> stu[i].west >> stu[i].paper;
		stu[i].sum = func(i);
		stu[i].num = i;
		ans += stu[i].sum;
	}
	sort(stu, stu + n, cmp);
	cout << stu[0].name << endl << stu[0].sum << endl << ans << endl;


	return 0;
}