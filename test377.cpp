#define _CRT_SECURE_NO_WARING


#include <iostream>
#include <stack>
using namespace std;

int main() {
	char str[305];
	stack<int> sta;
	cin >> str;
	for (int i = 0; str[i]; i++) {
		if (str[i] == '(') {
			sta.push(i);
		}
		else if (str[i] == ')') {
			if (sta.empty()) {
				cout << "NO" << endl;
				return 0;
			}
			else {
				sta.pop();
			}
		}		
	}
	if (sta.empty()) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}
	return 0;
}