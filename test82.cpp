﻿//又到了伐木的季节呢！亚布力林业局引进了一台新的伐木设备，这种设备能设定一个高度值（整数），
//并将所有树木大于此高度的部分锯下来。​ 例如，有四棵树的高度分别为 20M 17M 15M 10M，把设备的高度设定为 15M，
//那么设备运行过后树的高度变为 15M 15M 15M 10M（从第一棵树锯下 5M，从第二棵树锯下 2M，总共锯下 7M）。​ 
//现在林业局需要至少锯下长度为 M 米的木头，因为国家推行的环保政策，林业局不能锯下过多的木材。
//需要将伐木设备的高度设定为多少才能使得获得的木材至少为 M 米？换句话说，如果再将高度升高一米，将得不到 M 米的木材，
//如果将高度减少一米，将不能通过环保政策。
//
//输入
//​ 第一行两个个整数 N 和 M，N 表示树木的数量，M 表示需要木材的长度。​ （1≤N≤1000000, 1≤M≤2000000000）​ 
//第二行 N 个整数表示每棵树的高度（≤1000000000）。所有数据必有解。
//
//输出
//​ 一个整数，表示伐木的最高高度。



#include <iostream>
using namespace std;

long long n, m, num[1000005], mmax;

long long func(long long x) {
	long long t = 0;
	for (int i = 0; i < n; i++) {
		if (num[i] > x) {
			t += num[i] - x;
		}
	}
	return t >= m;
}


long long bs() {
	long long l = 0, r = mmax;
	while (l != r) {
		long long mid = (l + r + 1) / 2;
		if (func(mid)) {
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
		mmax = max(mmax, num[i]);
	}
	cout << bs() << endl;
	return 0;
}