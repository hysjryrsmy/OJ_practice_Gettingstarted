#define _CRT_SECURE_NO_WARING
#include <iostream>
#include <queue>
using namespace std;

int main() {
	priority_queue<int, vector<int>, greater<int> > que;
	int n, ans = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		que.push(t);
	}
	while (que.size() != 1) {
		int t = que.top();
		que.pop();
		t += que.top();
		que.pop();
		ans += t;
		que.push(t);
	}
	cout << ans << endl;

	return 0;
}
