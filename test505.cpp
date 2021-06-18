#define _CRT_SECURE_NO_WARING

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int n;
string s[100005];

bool cmp(const string& a, const string& b) {
	return a + b > b + a;
}


int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}

	sort(s, s + n, cmp);
	for (int i = 0; i < n; i++) {
		cout << s[i];
	}
	cout << endl;
	return 0;
}