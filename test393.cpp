#include <iostream>
#include <cstdio>
using namespace std;

int n, k;
double num[10005], mmax;

int func(double x) {
	int t = 0;
	for (int i = 0; i < n; i++) {
		t += num[i] / x;
	}
	return t >= k;
}

double bs() {
	double l = 0, r = mmax;
	while (r - l > 0.00001) {
		double mid = (l + r) / 2;
		if (func(mid)) {
			l = mid;
		}
		else {
			r = mid;
		}
	}
	return r;
}

int main() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> num[i];
		mmax = max(mmax, num[i]);
	}
	double ans = bs();
	printf("%.2f\n", (int)(ans * 100) / 100.0); 
	//printf("%.2f\n", ans - 0.005);
	return 0;
}