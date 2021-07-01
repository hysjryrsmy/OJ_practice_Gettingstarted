#include <iostream>
using namespace std;

int n, m, num[100005], mmax;

int func(int x) {
	int t = 0;
	for (int i = 0; i < n; i++) {
		t += num[i] / x;
	}
	return t;
}


int bs() {
	int l = 1, r = mmax;
	while (l != r) {
		int mid = (l + r + 1) / 2;
		int s = func(mid);
		if (s >= m) {
			l = mid;
		}
		else {
			r = mid - 1;
		}
	}
	return r;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> num[i];
		mmax = max(mmax, num[i]);
	}
	cout << bs() << endl;




	return 0;
}