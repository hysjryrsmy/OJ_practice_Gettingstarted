
#define _CRT_SECURE_NO_WARING

#include <iostream>
using namespace std;

//题目描述
//​ 给定一个只包含大写字母 ′′A′′−′′Z′′ 的字符串，找到相邻两个元音字母之间间隔最大的距离。
//
//​ 注：元音字母为 AEIOU。
//
//输入
//​ 共一行，一个长度不大于 100 的字符串。
//
//输出
//​ 一个整数表示相邻两个元音字母之间的最大距离。


int main() {
	char s[105];
	int last = 999, ans = 0;
	cin >> s;
	for (int i = 0; s[i]; i++) {
		if (s[i] == 'A' || s[i] == 'E' || s[i] == 'O' || s[i] == 'U' || s[i] == 'I') {
			ans = max(ans, i - last);
			last = i;
		}
	}
	cout << ans << endl;

	return 0;
}

