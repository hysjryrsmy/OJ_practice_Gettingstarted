#define _CRT_SECURE_NO_WARING

#include <iostream>
#include <algorithm>
using namespace std;

int n, num[1005], ans;

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> num[i];
	}
	sort(num + 1, num + n + 1);
	for (int i = n; i >= 1; i -= 2) {
		if (i == 1) {
			ans += num[i];
			break;
		}
		else if (i == 2) {
			ans += num[2];
			break;

		}
		else if (i == 3) {
			ans += num[2] + num[1] + num[3]; 
			break;
		}
		else {
	//num[i]（最快+最慢） + num[1]（最快） + num[i - 1]（最快+次慢） + num[1]（最快）： 第一种方案-> 传递手电效率高
	//num[2]（最快+次快）+ num[1]（最快） + num[i]（最慢+次慢） + num[2]（次快） :  第二种方案 -> 过河效率高
			ans += min(num[i] + num[1] + num[i - 1] + num[1], num[2] + num[1] + num[i] + num[2]);
		}
	}
	cout << ans << endl;
	return 0;
}