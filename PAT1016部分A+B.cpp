/*1016. ����A+B (15)

������A�ġ�DA��Ϊ1λ���������֡�����Ϊ��A������DA��ɵ�������PA��
���磺����A = 3862767��DA = 6����A�ġ�6���֡�PA��66����ΪA����2��6��

�ָ���A��DA��B��DB�����д�������PA + PB��

�����ʽ��

������һ�������θ���A��DA��B��DB���м��Կո�ָ�������0 < A, B < 1010��

�����ʽ��

��һ�������PA + PB��ֵ��

��������1��
3862767 6 13530293 3
�������1��
399
��������2��
3862767 1 13530293 8
�������2��
0*/

#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

//�Ƚϼ򵥣���������stl�����count
//���о���Ҫ����������ĳ���������ַ����е�����Ϊ0����insert��ʱ������
//����Ҫ�ּ�����������������ֻ���0��


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