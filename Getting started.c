#define _CRT_SECURE_NO_WARING
#include <stdio.h>

//1. #122.时间转换
//输入一个整数 t，计算当天从 00:00 : 00 开始经过 t 秒以后的时间。
//输出格式如下：
//​ 输出的格式按照12小时制输出；
//​ 如果时间在中午 12:00 : 00 之前，那么输出 hh : mm:ss  am；
//​ 如果时间在中午 12 : 00 : 00 至下午 01 : 00 : 00 之间，那么输出 12 : mm : ss  midnoon；
//​ 如果时间在下午 01 : 00 : 00 之后，那么输出 hh : mm:ss  pm；
//​ 其中 h, m, s 分别表示小时、分钟、秒，如果不足两位，前面用 0 代替。
/*
int main(){
	int t;
	scanf("%d\n", &t);
	if (t < 43200) {
		printf("%02d:%02d:%02d am\n", t / 3600, t % 3600 / 60, t % 60);
	}
	else if (t < 43200 + 3600){
		printf("%02d:%02d:%02d midnoon\n", t / 3600, t % 3600 / 60, t % 60);
	}
	else {
		t -= 43200;
		printf("%02d:%02d:%02d pm\n", t / 3600, t % 3600 / 60, t % 60);
	}

	return 0;
}
*/


//2. #127. 高利贷
//高利贷是指利息特别高的贷款。假如某高利贷的月利息是 6 % ，某人贷款 10000 元，第一个月过后，此人需要还 10000∗(1 + 6 %) = 10600 元，
// 第二个月需要还 10600∗(1 + 6 %) = 11236 元，如此计算下去，也就是每个月的利息会作为下个月的本金。
//​ 某人借该高利贷 x 元，求 n 个月以后此人需要还多少钱。（1≤x≤100000, 0≤n≤5）

/*
int main()
{
	int x, n;
	scanf("%d %d\n", &x, &n);
	double m = x;
	for (int i = 0; i < n; i++) {
		m = m * 1.06;
	}
	printf("%d\n", (int)m);
	return 0;
}
*/


//3.  #128. n个数的平均数
//读入 n 个整数，计算它们的平均值。
//输入
//​第一行一个整数 n 表示需要读入的整数的数量。（2≤n < 1000）； 第二行为 n 个整数 X1, X2……Xn。（1≤Xn≤10000）
//输出
//输出一个保留两位小数的浮点数，为 n 个整数的平均数。
/*
int main()
{
	int sum = 0, n;
	scanf_s("%d\n", &n);
	for (int i = 0; i < n; i++)
	{
		int temp;
		scanf_s("%d", &temp);
		sum += temp;
	}
	printf("%.2f\n", 1.0 * sum / n);
	return 0;
}
*/


//4.  #129. n个数的最小数
//​ 读入 n 个整数，找出其中最小的数。
//输入
//​第一行一个整数 n 表示需要读入的整数的数量。（2≤n < 1000）
//第二行为 n 个整数 X1, X2……Xn。（1≤Xn≤10000）
//输出
//输出 n 个整数中最小的数。
/*
int main()
{
	int n, min = 0;
	scanf_s("%d\n", &n);
	for (int i = 0; i < n; i++)
	{
		int temp;
		scanf_s("%d", &temp);
		if (i == 0) {  //第一次读取这个数字
			min = temp;
		}
		else if (temp < min){
			min = temp;
		}
	}
	printf("%d\n", min);
	return 0;
}
*/


// 5. #132 .n个数的极差
/*
int main()
{
	int n, min, max;
	scanf_s("%d\n", &n);
	for (int i = 0; i < n; i++)
	{
		int temp;
		scanf_s("%d\n", &temp);
		if (i == 0) {  //第一次读取这个数字
			max = min = temp;
		}
		if (temp > max)
		{
			max = temp;
		}
		if (temp < min)
		{
			min = temp;
		}
	}
	printf("%d\n", max - min);

	return 0;
}
*/


// 6. #132 . n个数的乘法
/*
int main()
{
	int n;
	scanf_s("%d\n", &n);
	long long mul = 1;
	for (int i = 0; i < n; i++)
	{
		int temp;
		scanf_s("%d\n", &temp);
		mul *= temp;
	}
	printf("%lld\n", mul);
	return 0;
}
*/



//复利
/*
int main()
{
	int m, n;
	scanf("%d %d\n", &m, &n);
	double ans = 0;
	for (int i = 0; i < n; i++)
	{
		ans = (ans + m) * 1.00417;
	}
	printf("$%.2f\n", ans);
	return 0;
}
*/


//#135. X天后的日期 :  给定一个合法的日期，求 x 天后的日期。
// 第一行输入一个整数 x，表示天数。第二行输入三个整数y，m，d，分别表示当前日期的年月日
// 输出为一行，共三个整数，分别表示x天后日期的年月日

/*
int day_month(int y, int m)
{
	switch (m){
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12: return 31;
	case 4:
	case 6:
	case 9:
	case 11: return 30;
	}
	if ((y % 400 == 0) || (y % 100 != 0) && (y % 4 == 0)) 
	{
		return 29;
	}
	else
	{
		return 28;
	}
}

int main()
{
	int x, y, m, d;
	scanf_s("%d\n", &x);
	scanf_s("%d %d %d", &y, &m, &d);
	d += x;
	while (d > day_month(y, m))
	{
		d -= day_month(y, m);
		m++;
		if (m == 13)
		{
			m = 1;
			y++;
		}
	}
	printf("%d %d %d\n", y, m, d);
	return 0;
}
*/

//另一种方法
int mont(int n) {
	if ((n % 4 == 0 && n % 100 != 0) || n % 400 == 0) return 0;
	else return 1;
}
int main() {
	int n;
	scanf_s("%d\n", &n);
	int y, m, d;
	int mon[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31 ,30, 31, 30, 31 };
	scanf_s("%d %d %d", &y, &m, &d);
	if (mont(y)) mon[2] = 28;
	else mon[2] = 29;
	for (int i = 1; i <= n; i++) {
		d += 1;
		if (d > mon[m]) {
			d = d - mon[m];
			m++;
			if (m > 12) {
				y++;
				m = 1;
				if (mont(y)) continue;
				mon[2] = 29;
			}
		}
	}
	printf("%d %d %d", y, m, d);
	return 0;
}



// #134.十一的倍数 
//给定两个数字 a,b，按照从小到大的顺序输出这两个数字之间（含）所有 11 的倍数。
//输入两个正整数 a,b。（0<a≤b≤1000）
//输出为一行，按照从小到大的顺序输出 a,b 之间（含）所有 11 的倍数，每两个数字用空格隔开. 注意末尾不要有多余的空格
/*
int main()
{
	int a, b;
	scanf_s("%d %d\n", &a, &b);
	int flag = 0;
	for (int i = a; i <= b; i++)
	{
		if (i % 11 == 0)
		{
			if (flag == 1)
			{
				printf(" ");
			}
			printf("%d", i);
			flag = 1;
		}
	}
	return 0;
}
*/