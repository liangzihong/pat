#include<iostream>
#include<cstdio>
#include<string>
#include<cctype>
using namespace std;
//�������ǿ�������Ȼ����Ҫ�û�����Ϥ�����룬�鷳��ҲҪ����Ȼgetline��cin�� �� ���������е�Բ���
//��ʵ����Ҫ����������У�������������֮������кܶ಻ͬ�ķ��ţ�����Щ��������Ҫʡ�Եģ�������Ҫ������

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