#define _CRT_SECURE_NO_WARING

#include <iostream>
#include <queue>
using namespace std;

struct node {
	int x, y;
};

int n, m, k, ans[3005][3005];
int dir[4][2] = { 0,1,1,0,0,-1,-1,0 };
char mmap[3005][3005];
queue<node> que;

void func(int x, int y) {
	for (int i = 0; i < 4; i++) {
		int xx = x + dir[i][0];
		int yy = y + dir[i][1];

		if (mmap[xx][yy] != 0 && mmap[x][y] != mmap[xx][yy] && ans[xx][yy] == 0 ) {
			que.push((node){ xx, yy });
			ans[xx][yy] = 1;	
			func(xx, yy);
		}
	}
}

int main() {
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		cin >> &mmap[i][1];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (ans[i][j] == 0) {
				que.push((node){ i, j });
				ans[i][j] = 1;
				func(i, j);
				int cnt = que.size();
				while (!que.empty()) {
					node temp = que.front();
					que.pop();
					ans[temp.x][temp.y] = cnt;
				}
			}
		}
	}
	for (int i = 0; i < k; i++) {
		int a, b;
		cin >> a >> b;
		cout << ans[a][b] << endl;
	}

	return 0;
}