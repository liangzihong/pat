#include<iostream>
#include<cstdio>
#include<string>
#include<cctype>
using namespace std;
//这题很勉强，输入果然还是要用回最熟悉的输入，麻烦点也要，不然getline（cin， ， ‘】’）有点吃不消
//其实还是要理解好题意才行，它两队中括号之间可以有很多不同的符号，而这些符号是你要省略的！！很重要的题意

int main()
{
	string hands[20];
	string eyes[20];
	string mouths[20];

	int handnum = 0; int eyenum = 0; int mouthnum = 0;
	
	int i = 1;
	while(1)
	{
		char ch;
		if(cin>>ch&& ch== '[')
		{
			while (cin>>ch && ch != ']')
			{
				hands[i] += ch;
			}
			i++;
		}
		if (cin.peek() == '\n')
		{
			handnum = i-1; break;
		}
	}
	i = 1;
	while (1)
	{
		char ch;
		if (cin >> ch&& ch == '[')
		{
			while (cin >> ch && ch != ']')
			{
				eyes[i] += ch;
			}
			i++;
		}
		if (cin.peek() == '\n')
		{
			eyenum = i-1; break;
		}
	}
	i = 1;
	while (1)
	{
		char ch;
		if (cin >> ch&& ch == '[')
		{
			while (cin >> ch && ch != ']')
			{
				mouths[i] += ch;
			}
			i++;
		}
		if (cin.peek() == '\n')
		{
			mouthnum = i-1; break;
		}
	}
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int a, b, c, d, e;
		cin >> a >> b >> c >> d >> e;
		if (a > handnum || e > handnum || b > eyenum || d > eyenum || c > mouthnum
			|| a <= 0 || b <= 0 || c <= 0 || d <= 0 || e <= 0)
		{
			cout << "Are you kidding me? @\\/@" << endl;
		}
		else {
			cout << hands[a] << "(" << eyes[b] << mouths[c] << eyes[d] << ")" << hands[e] << endl;
		}
	}

	system("pause");
	return 0;
}