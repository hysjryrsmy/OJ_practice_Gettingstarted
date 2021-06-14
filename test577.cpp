#define _CRT_SECURE_NO_WARING
#include <iostream>
#include <map>
#include <string>
using namespace std;

void check(string& str) {
	for (int i = 0; i < str.size(); i++) {
		if (str[i] >= 'A' && str[i] <= 'Z') {
			str[i] += 'a' - 'A';
		}
	}
}

int main() {
	map<string, int> m;
	string str, ans;
	int ans_cnt = 0;
	while (cin >> str) {
		check(str);
		m[str]++;
		if (m[str] > ans_cnt) {
			ans_cnt = m[str];
			ans = str;
		}
		else if (m[str] == ans_cnt && str < ans) {
			ans_cnt = m[str];
			ans = str;
		}
	}
	cout << ans << " " << ans_cnt << endl;
	return 0;
}