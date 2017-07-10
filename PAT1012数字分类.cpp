/*1012. ���ַ��� (20)

����һϵ�����������밴Ҫ������ֽ��з��࣬���������5�����֣�

A1 = �ܱ�5����������������ż���ĺͣ�
A2 = ����5������1�����ְ�����˳����н�����ͣ�������n1-n2+n3-n4...��
A3 = ��5������2�����ֵĸ�����
A4 = ��5������3�����ֵ�ƽ��������ȷ��С�����1λ��
A5 = ��5������4��������������֡�
�����ʽ��

ÿ���������1������������ÿ�����������ȸ���һ��������1000��
������N��������N��������1000�Ĵ�����������������ּ��Կո�ָ���

�����ʽ��

�Ը�����N��������������ĿҪ�����A1~A5����һ����˳����������ּ��Կո�ָ�������ĩ�����ж���ո�

������ĳһ�����ֲ����ڣ�������Ӧλ�������N����

��������1��
13 1 2 3 4 5 6 7 8 9 10 20 16 18
�������1��
30 11 2 9.7 9
��������2��
8 1 2 4 5 6 7 9 16
�������2��
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


	//��һ������
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

	//�ڶ�������
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
		(cnt == 1) ? cout << "N " : cout << a2 << " ";             //����ע�͵�cnt==1�����Ƿ�ͨ�������ͨ��������ʵPAT��ˮ
	}


	//����������
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

	//���ĸ�����
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

	//���������
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