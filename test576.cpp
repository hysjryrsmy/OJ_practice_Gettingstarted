#define _CRT_SECURE_NO_WARING
#include <iostream>
#include<map>	
#include <string>
using namespace std;



int main() {
	map<string, int> huo, qian;
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		string t;
		int t2, t3;
		cin >> t >> t2 >> t3;
		huo[t] = t3;
		qian[t] = t2;
	}
	long long ans = 0;
	for (int i = 1; i <= k; i++) {
		string t;
		int t2;
		cin >> t >> t2;
		if (huo[t] >= t2) {
			huo[t] -= t2;
			ans += t2 * qian[t];
		}
		else {
			cout << "-" << i << endl;
			return 0;
		}
	}
	cout << ans << endl;

	return 0;
}