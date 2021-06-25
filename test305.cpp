#define _CRT_SECURE_NO_WARING
#include <iostream>
#include <queue>
using namespace std;

struct node {
	int x, y, step;
};

int n, m, x, y;
char mmap[105][105];

int dir[8][2] = {
	1,0,0,1,-1,0,0,-1,
	1,1,1,-1,-1,1,-1,-1
};

int main() {
	
	cin >> m >> n >> y >> x;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> mmap[i][j];	
		}
	}
	queue<node> que;
	que.push({(n - x + 1), y, 0});
	mmap[(n - x + 1)][y] = 0;
	int ans = 0;
	while (!que.empty()) {
		node temp = que.front();
		ans = temp.step;
		que.pop();
		for (int i = 0; i < 8; i++) {
			int x2 = temp.x + dir[i][0];
			int y2 = temp.y + dir[i][1];

			if (mmap[x2][y2] == '.') {
				mmap[x2][y2] = '0';
				que.push({ x2,y2,temp.step + 1 });
			}
		}
	}

	cout << ans << endl;
	return 0;
}