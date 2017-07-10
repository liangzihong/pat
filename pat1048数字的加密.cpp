//pat1048
/*本题要求实现一种数字加密方法。首先固定一个加密用正整数A，对任一正整数B，将其每1位数字与A的对
应位置上的数字进行以下运算：对奇数位，对应位的数字相加后对13取余——这里用J代表10、Q代表11、
K代表12；对偶数位，用B的数字减去A的数字，若结果为负数，则再加10。这里令个位为第1位。

输入格式：

输入在一行中依次给出A和B，均为不超过100位的正整数，其间以空格分隔。

输出格式：

在一行中输出加密后的结果。

输入样例：
1234567 368782971
输出样例：
3695Q8118*/




//因为计数都是从各位开始，所以正常想法就是先把数字倒序，再进行处理
//然后将短的数字列补0，使两个字符数组长度都相等，并且都是数字
//然后就可以进行处理
//1、一半数字是相加后取余13，字符串的数字可以用arr[i]-'0'来表示数字
//2、根据上面的处理，其他比较容易
//行了

#include<iostream>
#include<cstring>
using namespace std;

void change(char arr[])
{
	int length = strlen(arr);
	char temp;
	for (int i = 0; i <= (length - 1) / 2; i++)
	{
		temp = arr[i];
		arr[i] = arr[length - 1 - i];
		arr[length - 1 - i] = temp;
	}
	return;
}

void output(char*arr1, char*arr2)
{
	int len1 = strlen(arr1);
	int len2 = strlen(arr2);
	int lensmall = (len1 < len2) ? len1 : len2;
	int len = (len1 > len2) ? len1 : len2;
	char*s = new char[len+1];
	int a;

	if (len1 < len2)
	{
		for (int i = len1; i < len2; i++)
		{
			arr1[i] = '0';
		}
		arr1[len2] = '\0';
	}

	if (len2 < len1)
	{
		for (int i = len2; i < len1; i++)
		{
			arr2[i] = '0';
		}
		arr2[len1] = '\0';
	}


	for (int i = 0; i <= len-1; i++)
	{
		if (i % 2 == 0)
		{
			a =( (arr1[i] - '0') + (arr2[i] - '0')) % 13;
			if (a < 10)
			{
				s[i] = char(a + 48);
			}
			else
			{
				switch (a)
				{
				case 10 :s[i] = 'J'; break;
				case 11:s[i] = 'Q';break;
				case 12:s[i] = 'K'; break;
				}
			}
		}
		else {
			a = (arr2[i] - '0') - (arr1[i] - '0');
			a = (a < 0) ? (a + 10) : a;
			s[i] = char(a+48);
		}
	}
	s[len] = '\0';
	

	change(s);
	cout << s << endl;
}

int main()
{
	char arr1[102] = { '\0' };
	char arr2[102] = { '\0' };
	cin >> arr1 >> arr2;
	change(arr1);
	change(arr2);
	output(arr1, arr2);
	system("pause");
	return 0;
}