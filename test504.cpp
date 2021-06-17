#define _CRT_SECURE_NO_WARING
#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	int n;
	cin >> s >> n;
	for (int i = 0; i < n; i++) {
		int ind = s.size() - 1;
		for (int j = 0; j < s.size() - 1; j++) {
			if (s[j] > s[j + 1]) {
				ind = j;
				break;
			}
		}
		s.replace(ind, 1, "");
	}
	int f = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] != '0') {
			f = 1;
		}if (f == 1) {
			cout << s[i];
		}
		
	}
	if (f == 0) {
		cout << 0;
	}
	cout << endl;
	return 0;
}