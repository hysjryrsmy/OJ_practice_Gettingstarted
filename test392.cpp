#define _CRT_SECURE_NO_WARING
#include <iostream>
#include <algorithm>
using namespace std;

//二分答案
// 1.分什么
// 分的就是问题的答案->最大距离
// 2.怎么求解
// 根据最大距离 能求出留下的瓶盖数
// 若瓶盖数大于等于b 说明距离可能继续加大
// 若瓶盖数小于b说明距离应该减小
// 3.特殊情况
// 根据分析此题属于11110000型问题
//小明小时候很贪玩，在他童年时期的某一天，他在地上丢了 A 个瓶盖，为了简化问题，
//我们可以当作这 A 个瓶盖丢在一条直线上，现在他想从这些瓶盖里找出 B 个，
//使得距离最近的 2 个距离最大，他想知道，最大可以到多少呢？

//输入
//​ 第一行两个整数 A, B。（2≤B≤A≤100, 000）
//​ 接下来 A 行，每行一个数，表示瓶盖的位置坐标 Ai。（1≤Ai≤100, 000, 000）

//输出
//​ 一个正整数，相邻的两个瓶盖的最大距离。

int n, m, num[100005], mmax;

int func() {
	int l = 1, r = mmax;
	while (l != r) {
		int mid = (l + r + 1) / 2;
		int cnt = 1, now = 0;
		for (int i = 1; i < n; i++) {
			if (num[i] - num[now] >= mid) {
				cnt++;
				now = i;
			}
		}
		if (cnt >= m) {
			l = mid;
		}
		else {
			r = mid - 1;
		}
	}
	return l;
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}
	sort(num, num + n);
	mmax = num[n - 1] - num[0];
	cout << func() << endl;


	return 0;
}