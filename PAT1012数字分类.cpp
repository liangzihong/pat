/*1012. 数字分类 (20)

给定一系列正整数，请按要求对数字进行分类，并输出以下5个数字：

A1 = 能被5整除的数字中所有偶数的和；
A2 = 将被5除后余1的数字按给出顺序进行交错求和，即计算n1-n2+n3-n4...；
A3 = 被5除后余2的数字的个数；
A4 = 被5除后余3的数字的平均数，精确到小数点后1位；
A5 = 被5除后余4的数字中最大数字。
输入格式：

每个输入包含1个测试用例。每个测试用例先给出一个不超过1000的
正整数N，随后给出N个不超过1000的待分类的正整数。数字间以空格分隔。

输出格式：

对给定的N个正整数，按题目要求计算A1~A5并在一行中顺序输出。数字间以空格分隔，但行末不得有多余空格。

若其中某一类数字不存在，则在相应位置输出“N”。

输入样例1：
13 1 2 3 4 5 6 7 8 9 10 20 16 18
输出样例1：
30 11 2 9.7 9
输入样例2：
8 1 2 4 5 6 7 9 16
输出样例2：
N 11 2 N 9*/

#include<iostream>
#include<iomanip>
#include<vector>
using namespace std;

int main()
{
	vector<int> arr;
	int input;
	cin >> input;
	while (cin >> input)
	{
		arr.push_back(input);
	}


	//第一个数字
	{
		int a1 = 0;
		for (int i = 0; i<arr.size(); i++)
		{
			if (arr[i] % 2 == 0 && arr[i] % 5 == 0)
			{
				a1 += arr[i];
			}
		}
		(a1 != 0) ? cout << a1 << " " : cout << "N" << " ";
	}

	//第二个数字
	{
		int cnt = 1;
		int a2 = 0;
		for (int i = 0; i < arr.size(); i++)
		{
			if (arr[i] % 5 == 1)
			{
				(cnt++ % 2 == 0) ? a2 -= arr[i] : a2 += arr[i];
			}
		}
		(cnt == 1) ? cout << "N " : cout << a2 << " ";             //等下注释掉cnt==1看看是否通过，如果通过，则其实PAT很水
	}


	//第三个数字
	{
		int a3 = 0;
		for (int i = 0; i < arr.size(); i++)
		{
			if (arr[i] % 5 == 2 )
			{
				a3++;
			}
		}
		(a3 == 0) ? cout << "N " : cout << a3 << " ";
	}

	//第四个数字
	{
		int a4=0;
		int cnt4 = 0;
		for (int i = 0; i < arr.size(); i++)
		{
			if (arr[i] % 5==3)
			{
				a4 += arr[i];
				cnt4++;
			}
		}
		cout << fixed << setprecision(1);
		(cnt4 == 0) ? cout << "N " : cout << double(a4) / cnt4<<" ";
	}

	//第五个数字
	{
		int a5 = 0;
		for (int i = 0; i < arr.size(); i++)
		{
			if (arr[i] % 5==4)
			{
				if (a5 <= arr[i])
				{
					a5 = arr[i];
				}
			}
		}
		cout << setprecision(0);
		a5 ? cout << a5 : cout << "N";
	}

	system("pause");
	return 0;
}