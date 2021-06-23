#define _CRT_SECURE_NO_WARING


#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int func(int x) {
	if (x % 7 == 0)  return 1;
	while (x) {
		if (x % 10 == 7) return 1;
		x /= 10;
	}
	return 0;
}


int main() {
	int n, x, t;
	cin >> n >> x >> t;
	queue<int> que;
	for (int i = 1, j = x; i <= n; i++, j++) {
		if (j > n) {
			j = 1;
		}
		que.push(j);
	}
	while (que.size() != 1) {
		if (func(t)) {
			que.pop();
		}
		else {
			que.push(que.front());
			que.pop();
		}
		t++;
	}
	cout << que.front() << endl;
	return 0;
}