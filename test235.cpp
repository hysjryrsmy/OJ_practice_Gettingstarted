#define _CRT_SECURE_NO_WARING

#include <iostream>
using namespace std;

//int n, ans[15];
//void print(int ind) {
//	for (int i = 1; i <= ind; i++) {
//		if (i != 1) cout << " ";
//		cout << ans[i];
//
//	}
//	cout << endl;
//}
//
//void func(int s, int ind) {
//	for (int i = s; i <= n; i++) {
//		ans[ind] = i;
//		print(ind);
//		func(i + 1, ind + 1);
//
//	}
//
//}
//
//int main() {
//	cin >> n;
//	func(1, 1);
//	return 0;
//}

int n, ans[15], ind = 1;
void print() {
	for (int i = 1; i <= ind; i++) {
		if (i != 1) cout << " ";
		cout << ans[i];

	}
	cout << endl;
}

void func(int s) {
	for (int i = s; i <= n; i++) {
		ans[ind] = i;
		print();
		ind++;
		func(i + 1);
		ind--;
	}

}

int main() {
	cin >> n;
	func(1);
	return 0;
}