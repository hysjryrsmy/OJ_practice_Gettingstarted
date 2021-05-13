#define _CRT_SECURE_NO_WARING
#include <stdio.h>

//#138. 输出A字三角形
// 输入一个正整数 n，并输出一个三角形，这个三角形有 n 行，第一行有 2n 个字母 A，之后每行字母 A 的数量会递减 2 个。
/*
int main()
{
	int n;
	scanf_s("%d\n", &n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < (n - i) * 2; j++)
		{
			printf("A");
		}
		printf("\n");
	}


	return 0;
}
*/
//另一种做法 
/*
int main()
{
    int input;
    scanf_s("%d", &input);
    char start = 'A';
    for (int i = input; i > 0; i--)
    {
        // 这个循环是行数相关
        for (int j = 0; j < 2 * i; j++)
        {
            printf("%c", start);
        }
        printf("\n");
    }
    return 0;
}
*/



//#140. 输出字母菱形
//输入一个正整数 n，并输出一个菱形，这个菱形有 2n−1 行，第一行有 1 个字母 A，之后的 n−1 行每行字母会变成上一行的下一个（A 的下一个是 B），
//且数量会递增 2 个，后面的 n+1 行至 2n−1 行，会变成上一行的上一个（B 的上一个是 A），且数量会递减 2 个，
//同时，我们需要在每行前输出一定数量的空格，以保证菱形居中，注意末尾不要有多余的输出。
/*
#include <stdio.h>
int main()
{
    int input;
    scanf_s("%d", &input);
    char start = 'A' - 1;
    for (int i = 1; i <= input * 2 - 1; i++)
    {
        int temp_condition = i;
        if (i > input)
        {
            temp_condition = input * 2 - i;
            start--;
        }
        else
        {
            start++;
        }

        for (int j = 0; j < input - temp_condition; j++)
        {
            printf(" ");
        }

        for (int j = 0; j < 2 * temp_condition - 1; j++)
        {
            printf("%c", start);
        }

        printf("\n");
    }

    return 0;
}
*/

//另一种做法
/*
int main()
{
    int n;
    scanf_s("%d", &n);
    for (int i = 1; i <= n; i++){
        for (int j = 0; j < (n - i); j++){
            printf(" ");
        }
        for (int j = 0; j < 2 * i - 1; j++){
            printf("%c", (char)('A' + i - 1));
        }
        printf("\n");
    }
    for (int i = n - 1; i > 0; i--){
        for (int j = 0; j < (n - i); j++){
            printf(" ");
        }
        for (int j = 0; j < 2 * i - 1; j++){
            printf("%c", (char)('A'+ i - 1));
        }
        printf("\n");
    }
    return 0;
}
*/



//#142. 五位质数回文数
//质数：除了 1 和它本身，没有其他因数。    回文数：正着看和反着看完全一样的数，如 12321,59595。
//给定两个五位正整数 a,b，找出这两个数之间（含）所有既是质数又是回文数的数。
//输入两个五位正整数 a,b。（10000≤a,b≤99999）
//输出一行，为从 a 到 b 之间所有的质数回文数，两个数字之间用空格隔开，最后一个数后没有空格。
/*
int is_prime(int n)
{
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)  return 0;
    }
    return 1;
}

int is_back(int n)
{
    if (n / 10000 == n % 10 && n / 1000 % 10 == n / 10 % 10){
        return 1;
    }
    else {
        return 0;
    }
}

int main()
{
    int a, b;
    scanf_s("%d %d", &a, &b);
    int flag = 0;
    for (int i = a; i <= b; i++)
    {
        if (is_prime(i) && is_back(i)) {
            if (flag == 1) {
                printf(" ");
            }
            printf("%d", i);
            flag = 1;
        }
    }
    return 0;
}
*/



//#143. 数字游戏
//给定两个四位正整数 a,b，找出这两个数之间（含）所有满足以下条件的数：
// ​ 1.这个四位数能被 6 整除；
//  2.千位数字与百位数字构成的两位数 AB 是一个质数；
//  3.十位数字与个位数字构成的两位数 CD 是一个完全平方数。
// 完全平方数：可以写成另一个数的平方的数
// 输入
//输入两个四位正整数 a,b。（1000≤a≤b≤9999）
// 输出两行
//第一行为从 a 到 b 之间所有满足条件的数，两个数字之间用空格隔开，最后一个数后没有空格
//第二行为满足条件的数的个数 n。

int is_prime(int n)
{
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)  return 0;
    }
    return 1;
}

int is_pow(int n) {
    switch (n) {
    case 1:
    case 4:
    case 9:
    case 16:
    case 25:
    case 36:
    case 49:
    case 64:
    case 81:  return 1;
    }
    return 0;
}

int main()
{
    int a, b;
    scanf_s("%d %d", &a, &b);
    int flag = 0, cnt = 0;
    for (int i = a; i <= b; i++)
    {
        if (i % 6 == 0 && is_prime(i / 100) && is_pow(i % 100))
        {
            if (flag == 1)
            {
                printf(" ");
            }
            printf("%d", i);
            flag = 1;
            cnt++;
        }
    }
    printf("\n");
    printf("%d\n", cnt);
    return 0;
}
