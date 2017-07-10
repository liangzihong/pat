/*1023. 组个最小数 (20)

给定数字0-9各若干个。你可以以任意顺序排列这些数字，但必须全部使用。目标是使得最后得到的数
尽可能小（注意0不能做首位）。例如：给定两个0，两个1，三个5，一个8，我们得到的最小的数就是10015558。

现给定数字，请编写程序输出能够组成的最小的数。

输入格式：

每个输入包含1个测试用例。每个测试用例在一行中给出10个非负整数，顺序表示我们拥有数字0、数字1、
……数字9的个数。整数间用一个空格分隔。10个数字的总个数不超过50，且至少拥有1个非0的数字。

输出格式：

在一行中输出能够组成的最小的数。

输入样例：
2 2 0 0 0 3 0 0 1 0
输出样例：
10015558*/

#include<iostream>
#include<string>
#include<algorithm>
#include<cctype>
using namespace std;

//第一次做的时候看错题，以为输入的就是数字，但是谁知不是，他会输入九个数字，分别代表0-9
//这九个数字的个数，所以其实也不难

//第一步，把拥有的数字都放在push_bach一个字符串中
//第二步，sort排序，找到一个非0的最小，把这个数字push_back进answer中，把这个字符变为‘a’；
//第三步，在sort排序，此时a会在最后，此时在用insert算法即可整堆插入进去

//注意：要时不时用迭代器替代。。。。

int main()
{
	string allnum;
	string answer;
	char ch;
	int num=0;
	int cnt;
	while(cin>>cnt)
	{
		for (int i = 0; i < cnt; i++)
		{
			allnum.push_back(num + '0');
		}
		num++;
	}
	sort(allnum.begin(), allnum.end());
	for (int i = 0; i < allnum.size(); i++)
	{
		if(allnum[i]!='0')
		{
			answer.push_back(allnum[i]);
			allnum[i] = 'a';
			break;
		}
	}
	sort(allnum.begin(), allnum.end());
	string::iterator it,it2;
	for (it = allnum.begin(); *it != 'a'; it++){}
	
	//it2 = answer.begin();
	//it2++;
	answer.insert(answer.end(), allnum.begin(), it);

	cout << answer << endl;
	system("pause");
	return 0;
}