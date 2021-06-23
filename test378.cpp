
#define _CRT_SECURE_NO_WARING
#include <iostream>
#include <string>
#include <stack>
using namespace std;


 
//题目描述
//​ 给出一个字符串，判断其中的左右括号是否匹配。
//
//​ 注：需同时判断左右圆括号 ′(′  和  ′)′，左右中括号 ′[′  和  ′]′，左右大括号 ′{ ′ 和 ′ }′。
//
//​ 不需要考虑括号之间的优先级的问题，也就是说，小括号包含大括号，也是被允许的。
//
//输入
//​ 一行一个字符串，以字符@为结尾。
//
//输出
//​ 若匹配，输出 YES，若不匹配，则输出 NO。


int main() {
	string s;
	stack<char> sta;
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
			sta.push(s[i]);
		}
		else if (s[i] == ')') {
			if (!sta.empty() && sta.top() == '(') {
				sta.pop();
			}
			else {
				cout << "NO" << endl;
				return 0;
			}
		}
		else if (s[i] == ']') {
			if (!sta.empty() && sta.top() == '[') {
				sta.pop();
			}
			else {
				cout << "NO" << endl;
				return 0;
			}

		}
		else if (s[i] == '}') {
			if (!sta.empty() && sta.top() == '{') {
				sta.pop();
			}
			else {
				cout << "NO" << endl;
				return 0;
			}
		}

	}
	if (!sta.empty()) {
		cout << "NO" << endl;
	}
	else {
		cout << "YES" << endl;
	}

	return 0;
}