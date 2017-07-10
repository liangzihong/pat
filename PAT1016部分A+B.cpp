/*1016. 部分A+B (15)

正整数A的“DA（为1位整数）部分”定义为由A中所有DA组成的新整数PA。
例如：给定A = 3862767，DA = 6，则A的“6部分”PA是66，因为A中有2个6。

现给定A、DA、B、DB，请编写程序计算PA + PB。

输入格式：

输入在一行中依次给出A、DA、B、DB，中间以空格分隔，其中0 < A, B < 1010。

输出格式：

在一行中输出PA + PB的值。

输入样例1：
3862767 6 13530293 3
输出样例1：
399
输入样例2：
3862767 1 13530293 8
输出样例2：
0*/

#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

//比较简单，就是用了stl里面的count
//还有就是要分情况，如果某个数字在字符串中的数量为0，你insert的时候会出错
//所以要分几种情况，单独输出或只输出0；


int main()
{
	string numa;
	string numb;
	char a;
	char b;
	string ansa;
	string ansb;
	int cnta;
	int cntb;

	cin >> numa;
	cin >> a;
	cin >> numb;
	cin >> b;

	cnta = count(numa.begin(), numa.end(), a);
	cntb = count(numb.begin(), numb.end(), b);
	if (cnta != 0 && cntb != 0)
	{
		ansa.insert(ansa.begin(), cnta, a);
		ansb.insert(ansb.begin(), cntb, b);
		cout << stol(ansa) + stol(ansb);
	}
	else if (cnta == 0 && cntb != 0)
	{
		cout << ansb;
	}
	else if(cnta!=0&&cntb==0)
	{
		cout << ansa;
	}
	else
	{
		cout << 0;
	}
	system("pause");
	return 0;
}