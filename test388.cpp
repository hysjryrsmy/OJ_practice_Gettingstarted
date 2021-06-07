#define _CRT_SECURE_NO_WARING
#include <iostream>
#include <algorithm>
using namespace std;

int num1[100005], num2[100005];

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {

		cin >> num1[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> num2[i]; 
	}
	sort(num2, num2 + m);
	long long sum = 0, f = 0;
	for (int i = 0; i < n; i++) {
		int l = 0, r = m - 1;
		while (l <= r)
		{
			int mid = (l + r) / 2;
			if (num2[mid] == num1[i]) {
				if (f == 1) cout << " ";
				f = 1;
				cout << num2[mid];
				sum += num2[mid];
				break;
			}
			if (num2[mid] < num1[i]){
				l = mid + 1;		
			}
			else {
				r = mid - 1;
			}
		}
	}
	cout << endl << sum << endl;

	return 0;
}