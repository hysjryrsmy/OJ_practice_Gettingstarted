#define _CRT_SECURE_NO_WARING
#include <cstdio>
#include <queue>
using namespace std;

struct person {
	int t, c;
};

int nation[100005];

int main() {
	queue<person> que;
	int n, con = 0;
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++) {
		int t, num;
		scanf_s("%d%d", &t, &num);
		while (!que.empty()) {
			person temp = que.front();
			if (t - temp.t < 86400)  break;
			que.pop();
			nation[temp.c]--;
			if (nation[temp.c] == 0) con--;
		}
		for (int j = 0; j < num; j++) {
			int temp;
			scanf_s("%d", &temp);
			que.push({ t, temp });
			if (nation[temp] == 0) con++;
			nation[temp]++;
		}
		printf("%d\n", con);
	}
	return 0;
}
