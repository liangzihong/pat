//pat1048
/*����Ҫ��ʵ��һ�����ּ��ܷ��������ȹ̶�һ��������������A������һ������B������ÿ1λ������A�Ķ�
Ӧλ���ϵ����ֽ����������㣺������λ����Ӧλ��������Ӻ��13ȡ�ࡪ��������J����10��Q����11��
K����12����ż��λ����B�����ּ�ȥA�����֣������Ϊ���������ټ�10���������λΪ��1λ��

�����ʽ��

������һ�������θ���A��B����Ϊ������100λ��������������Կո�ָ���

�����ʽ��

��һ����������ܺ�Ľ����

����������
1234567 368782971
���������
3695Q8118*/




//��Ϊ�������ǴӸ�λ��ʼ�����������뷨�����Ȱ����ֵ����ٽ��д���
//Ȼ�󽫶̵������в�0��ʹ�����ַ����鳤�ȶ���ȣ����Ҷ�������
//Ȼ��Ϳ��Խ��д���
//1��һ����������Ӻ�ȡ��13���ַ��������ֿ�����arr[i]-'0'����ʾ����
//2����������Ĵ��������Ƚ�����
//����

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