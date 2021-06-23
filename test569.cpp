#define _CRT_SECURE_NO_WARING


#include <iostream>
#include <stack>
#include <cstdio>
using namespace std;

struct node {
	double v, c, salt;
};

int main() {
	stack<node> sta;
	double v0, c0, salt0;
	int n;
	scanf("%lf %lf\n%d", &v0, &c0, &n);
	salt0 = v0 * c0 / 100;
	for (int i = 0; i < n; i++) {
		char t;
		cin >> t;
		if (t == 'P') {
			double vt, ct, saltt;
			cin >> vt >> ct;
			saltt = vt * ct / 100;
			v0 += vt;
			salt0 += saltt;
			sta.push((node){vt, ct, saltt});
		}
		else {
			if (!sta.empty()) {
				v0 -= sta.top().v;
				salt0 -= sta.top().salt;
				sta.pop();
			}
		}
		printf("%d %.5f\n", (int)v0, salt0 / v0 * 100);
	}
	return 0;
}