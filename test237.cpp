#define _CRT_SECURE_NO_WARING

#include <iostream>
using namespace std;

//题目描述
//​ 从 1−n 这 n 个整数排成一排并打乱次序，按字典序输出所有可能的选择方案。
//
//输入
//​ 输入一个整数 n。（1≤n≤8）
//
//输出
//​ 每行一组方案，每组方案中两个数之间用空格分隔。
//
//​ 注意每行最后一个数后没有空格。



int n, ans[10], mark[10], ind = 1;

void print() {
	for (int i = 1; i <= n; i++) {
		if (i != 1) cout << " ";
		cout << ans[i];
	}
	cout << endl;
}

void func() {
	if (ind > n) {
		print();
		return ;
	}
	for (int i = 1; i <= n; i++) {
		if (mark[i] == 0) {
			ans[ind] = i;
			mark[i] = 1;
			ind++;
			func();
			ind--;
			mark[i] = 0;
		}
	}

}


int main() {
	cin >> n;
	func();

	return 0;
}











