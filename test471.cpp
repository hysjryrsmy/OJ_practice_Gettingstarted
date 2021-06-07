#define _CRT_SECURE_NO_WARING

//471 大整数乘法
//题目描述
//​ 输入两个 100 位以内的正整数，输出它们的乘积。
//
//输入
//​ 共两行，每行一个大整数。
//
//输出
//​ 共一行，表示两数的乘积。




#include <iostream>
#include <cstring>
using namespace std;

char num1[105], num2[105];
int num3[105], num4[105], ans[305];

int main() {
	cin >> num1 >> num2;

	for (int i = strlen(num1) - 1, j = 1; i >= 0; i--, j++) {
		num3[j] = num1[i] - '0';
	}
	for (int i = strlen(num2) - 1, j = 1; i >= 0; i--, j++) {
		num4[j] = num2[i] - '0';
	}
	num3[0] = strlen(num1);
	num4[0] = strlen(num2);
	for (int i = 1; i <= num3[0]; i++) {
		for (int j = 1; j <= num4[0]; j++) {
			ans[i + j - 1] += num3[i] * num4[j];
		}
	}
	for (int i = 1; i <= num3[0] + num4[0]; i++) {
		if (ans[i] >= 10){
			ans[i + 1] += ans[i] / 10;
			ans[i] %= 10;
		}
		if (ans[i] != 0) {
			ans[0] = i;
		}

	}
	for (int i = ans[0]; i > 0; i--) {
		cout << ans[i];
	}
	cout << endl;
	return  0;
}