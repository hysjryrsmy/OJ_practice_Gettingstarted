#define _CRT_SECURE_NO_WARING
#include <iostream>
#include <queue>
using namespace std;


struct node {
	int x, y, step;
};

int n, ans[505][505];
int dir[12][2] = {
	1,2,1,-2,-1,2,-1,-2,
	2,1,2,-1,-2,1,-2,-1,
	2,2,2,-2,-2,2,-2,-2
};

int main() {
	queue<node> que;
	que.push((node){1, 1, 0});
	while (!que.empty()) {
		node temp = que.front();
		que.pop();
		for (int i = 0; i < 12; i++) {
			int x = temp.x + dir[i][0];
			int y = temp.y + dir[i][1];
			if (x < 1 || y < 1 || x > 500 || y > 500 || ans[x][y]) continue;
			ans[x][y] = temp.step + 1;
			que.push((node){x, y, ans[x][y]});
		}
	}
	ans[1][1] = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		cout << ans[a][b] << endl;
	}

	return 0;
}