#define _CRT_SECURE_NO_WARING
#include <iostream>
#include <cstdio>
#include<stack>
using namespace std;

struct node {
	double v, c, salt;
};

int main() {
	double v0, c0, salt0;
	stack<node> sta;
	cin >> v0 >> c0;
	salt0 = v0 * c0 / 100;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		char t;
		cin >> t;
		if (t == 'p') {
			double vt, ct, saltt;
			cin >> vt >> ct;
			saltt = vt * ct / 100;
			v0 += vt;
			salt0 += saltt;
			sta.push({ vt,ct,saltt });
		}
		if (t == 'Z') {
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