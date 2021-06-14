#define _CRT_SECURE_NO_WARING
#include <iostream>
#include<map>	
#include <string>
using namespace std;

string s[1001][5000];
string raw[1005];
int num[1005];
int n, m, total;
map<string, int> ma;

int main() {

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		string s1, s2;
		cin >> s1 >> s2;
		if (ma[s1] == 0) {
			total++;
			ma[s1] = total;
			raw[total] = s1;
		}
		int x = ma[s1];
		s[x][num[x]] = s2;
		num[x]++;

	}
	for (int i = 1; i <= total; i++) {
		cout << raw[i];
		int x = ma[raw[i]];
		for (int j = 0; j < num[i]; j++) {
			cout << " " << s[x][j];
		}
		cout << endl;
	}



	return 0;
}