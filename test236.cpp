#define _CRT_SECURE_NO_WARING

#include <iostream>
using namespace std;

//题目描述
//​ 从 1−n 这 n 个整数中随机选取 m 个，每种方案里的数从小到大排列，按字典序输出所有可能的选择方案。
//
//输入
//​ 输入两个整数 n, m。（1≤m≤n≤10）
//
//输出
//​ 每行一组方案，每组方案中两个数之间用空格分隔。
//
//​ 注意每行最后一个数后没有空格。

int n, m, ans[15], ind = 1;

void printf() {
	for (int i = 1; i <= m; i++) {
		if (i != 1) cout << " ";
		cout << ans[i];
	}
	cout << endl;
}

void func(int s, int left) {
	if (left == 0) {
		printf();
		return ;
	}
	for (int i = s; i <= n; i++) {
		ans[ind] = i;
		ind++;
		func(i + 1, left - 1);
		ind--;
	}
}


int main() {
	cin >> n >> m;
	func(1, m);

	return 0;
}