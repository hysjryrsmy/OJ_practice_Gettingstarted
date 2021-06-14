
#define _CRT_SECURE_NO_WARING
#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
	map<string, int> m;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string t;
		int t1;
		cin >> t >> t1;
		m[t] = t1;
	}
	cin >> n;
	for (int i = 0; i < n; i++) {
		string t;
		cin >> t;
		cout << m[t] << endl;
	}
	return 0;
}