#define _CRT_SECURE_NO_WARING
#include <iostream>
#include <string>
using namespace std;

int n, num[105], sum, avg, ans;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num[i];
		sum += num[i];
	}
	avg = sum / n;
	for (int i = 0; i < n; i++) {
		if (num[i] != avg) {
			ans++;
			num[i + 1] += num[i] - avg;
			num[i] = avg;
		}
	}
	cout << ans << endl;
	return 0;
}