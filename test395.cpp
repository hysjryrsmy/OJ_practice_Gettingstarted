#define _CRT_SECURE_NO_WARING
#include <iostream>
using namespace std;


//395.复制书稿
//现在要把 m 本有顺序的书分给 k 人复制（抄写），每一个人的抄写速度都一样，一本书不允许给两个（或以上）的人抄写，分给每一个人的书，必须是连续的，
//比如不能把第一、第三、第四本书给同一个人抄写。现需要设计一种方案，使得复制时间最短。复制时间为抄写页数最多的人用去的时间。
//输入
//​ 第一行两个整数 m, k。（1≤k≤m≤500）
//​ 第二行 m 个整数，第 i 个整数表示第 i 本书的页数 Ni。
//输出
//​ 共 k 行，每行两个整数，第 i 行表示第 i 个人抄写的书的起始编号和终止编号。
//k 行的起始编号应该从小到大排列，如果有多解，则尽可能让前面的人少抄写。数据保证每个人都有书可抄。

int m, k, num[505], ans[505][2], l, r;

int check(int mid) {
	int sum = 0, s = 0;
	for (int i = 0; i < m; i++) {
		if (sum + num[i] == mid) {
			sum = 0;
			s++;
		}
		else if (sum + num[i] > mid) {
			sum = num[i];
			s++;
		}
		else {
			sum += num[i];
		}
	}
	if (sum != 0) {
		s++;
	}
	return s;
}
int main() {
	cin >> m >> k;
	for (int i = 0; i < m; i++) {
		cin >> num[i];
		r += num[i];
	}
	while (l != r) {
		int mid = (l + r) / 2;
		int s = check(mid);
		if (s > k) {
			l = mid + 1;
		}
		else {
			r = mid;
		}
	}
	ans[k][1] = m;
	int now = num[m - 1], j = k;
	for (int i = m - 2; i >= 0; i--) {
		if (now + num[i] > l) {
			ans[j][0] = i + 2;
			j--;
			now = num[j];
			ans[j][1] = i + 1;
		}
		else if (now + num[i] == l) {
			ans[j][0] = i + 1;
			j--;
			i--;
			now = num[i];
			ans[j][1] = i + 1;
		}
		else {
			now += num[i];
		}
	}
	ans[1][0] = 1;
	for (int i = 1; i <= k; i++) {
		cout << ans[i][0] << " " << ans[i][1] << endl;
	}
	return 0;
}