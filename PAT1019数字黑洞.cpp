#include<iostream>
#include<string>
#include<algorithm>
#include<cctype>
#include<iomanip>
#include<cstdlib>
using namespace std;
/*如果N的4位数字全相等，则在一行内输出“N - N = 0000”；否则将计算的每一步在一
行内输出，直到6174作为差出现，输出格式见样例。注意每个数字按4位数格式输出。

输入样例1：
6767
输出样例1：
7766 - 6677 = 1089
9810 - 0189 = 9621
9621 - 1269 = 8352
8532 - 2358 = 6174
输入样例2：
2222
输出样例2：
2222 - 2222 = 0000*/




void function(int a, char s[])        //itoa的自己写的版本，这里没有把字符串重新倒序
									//因为这题四个数字可以任意排序，所以没必要排序了
{										//偷懒懒得就懒
	int idx = 0;
	while (a > 0)
	{
		s[idx++] = '0' + a % 10;
		a = a / 10;
	}
	s[idx] = 0;
}


bool cmp(char a, char b)
{
	if (a > b)
		return true;
	else
		return false;
}     //排序用得，这里要由大到小排

int change(string & a)
{
	int cnt = 0;
	int res = 0;
	while (cnt<a.size())
	{
		res = res * 10 + a[cnt++] - '0';
	}
	return res;
}  //把字符串变成int的函数，用整数相减比字符串好



int main()
{
	int bigger=0;
	int smaller=0;
	string bigstr;
	string smastr;
	string num;
	char arr[20];
	char c;
	cin.get(c);
	while (isdigit(c))       //如果是数字的就push进string；
								//如果不是数字就说明已经输完了
	{
		num.push_back(c);
		cin.get(c);
	}
	if (num[0] == num[1]&&num[0] == num[2]&&num[0] == num[3])   //四个相等时，特殊输出
	{
		cout << num << " - " << num << " = " << "0000\n";
		//exit(EXIT_FAILURE);
	}
	else
	{
		while (bigger-smaller != 6174)
		{
			while (num.size() < 4)          //为字符串补0.如果不够4位，则在前面补0；这里后面也行，反正不按顺序也可以
			{
				num.push_back('0');
			}
			//排序，并且记录下来，int和string都记录，int要来相减，string拿来规范输出
			sort(num.begin(), num.end());
			smaller = change(num); smastr = num;

			//排序，并且记录下来，int和string都记录，int要来相减，string拿来规范输出
			sort(num.begin(), num.end(), cmp);
			bigger = change(num); bigstr = num;

			cout << bigstr << " - "
				<< smastr << " = ";
			
			//这里因为懒得写把int又变成字符串的函数，所以直接补0，算了。。。。。。
			if (bigger - smaller < 10)
				cout << "000";
			else if (bigger - smaller < 100)
				cout << "00";
			else if (bigger - smaller < 1000)
				cout << "0";
			cout<< bigger - smaller << endl;

			function(bigger - smaller, arr);//把得数又变回字符串，这里可以不按顺序
			num.erase(num.begin(), num.end());//删掉以前的字符串
			num = arr;                    //直接string对c型字符串赋值，可以不够4位，因为循环开始时会补
		}
	}
	system("pause");
	return 0;
}