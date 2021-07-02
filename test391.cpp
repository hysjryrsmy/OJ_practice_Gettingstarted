#include <iostream>
using namespace std;

long long n, m, num[1000005], l, r;

long long func(long long x) {
	long long cnt = 0, now = 0;
	for (int i = 0; i < n; i++) {
		if (now + num[i] > x) {
			cnt++;
			now = num[i];
		}
		else if (now + num[i] == x) {
			cnt++;
			now = 0;
		}
		else {
			now += num[i];
		}
	}
	if (now != 0) {
		cnt++;
	}
	return cnt <= m;
}


long long bs() {
	while (l != r) {
		long long mid = (l + r) / 2;
		if (func(mid)) {
			r = mid;
		}
		else {
			l = mid + 1;
		}
	}
	return r;
}


int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> num[i];
		l = max(l, num[i]);
		r += num[i];
	}
	cout << bs() << endl;



	return 0;
}