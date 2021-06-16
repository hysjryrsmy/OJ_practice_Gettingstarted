
#define _CRT_SECURE_NO_WARING
#include <iostream>
using namespace std;

struct node {
	char s[4];
	int s1, s2, flag;
};


node bl[15];
int cnt = 1, ans;


int main() {
	while (cin >> bl[cnt].s) {
		
		//一击全中
		if (bl[cnt].s[0] == '/') {
			bl[cnt].s1 = 10;
			bl[cnt].s2 = 10;
			bl[cnt].flag = 2;
		}
		
		//二击全中
		else if (bl[cnt].s[1] == '/') {
			bl[cnt].s1 = bl[cnt].s[0] - '0';
			bl[cnt].s2 = 10;
			bl[cnt].flag = 1;
		}
		
		//没全中
		else {
			bl[cnt].s1 = bl[cnt].s[0] - '0';
			bl[cnt].s2 = bl[cnt].s1 + bl[cnt].s[1] - '0';
		}
		cnt++;
	}
	for (int i = 1; i <= 10; i++) {
		ans += bl[i].s2;

		//加下两球
		if (bl[i].flag == 2) {

			//下一局是否一击全中
			if (bl[i + 1].flag == 2) {
				ans += 10 + bl[i + 2].s1;
			}
			else {
				ans += bl[i + 1].s2;
			}
		}

		//加下一球
		else if (bl[i].flag == 1) {
			ans += bl[i + 1].s1;
		}
	}
	cout << ans << endl;



	return 0;
}