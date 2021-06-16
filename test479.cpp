
#define _CRT_SECURE_NO_WARING

#include <iostream>
#include <cmath>
using namespace std;


int ans21[5005][2], ans11[10005][2], cnt21, cnt11;
char s[30];

//输出
void print() {    
	for (int i = 0; i <= cnt11; i++) {
		cout << ans11[i][0] << ":" << ans11[i][1] << endl;
	}
	cout << endl;
	for (int i = 0; i <= cnt21; i++) {
		cout << ans21[i][0] << ":" << ans21[i][1] << endl;   
	}
}

int main() {
	while (cin >> s) {
		for (int i = 0; s[i]; i++) {
			if (s[i] == 'E') {
				print();
				return 0;
			}

			//计分
			if (s[i] == 'W') {
				ans21[cnt21][0]++;
				ans11[cnt11][0]++;
			}
			else {
				ans21[cnt21][1]++;
				ans11[cnt11][1]++;
			}

			//判断一局是否结束
			if ((ans21[cnt21][0] >= 21 || ans21[cnt21][1] >= 21) && abs(ans21[cnt21][0] - ans21[cnt21][1]) >= 2) {
				cnt21++;
			}
			if ((ans11[cnt11][0] >= 11 || ans11[cnt11][1] >= 11) && abs(ans11[cnt11][0] - ans11[cnt11][1]) >= 2) {
				cnt11++;
			}

		}
	}
	return 0;
}