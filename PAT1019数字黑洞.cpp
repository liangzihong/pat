#include<iostream>
#include<string>
#include<algorithm>
#include<cctype>
#include<iomanip>
#include<cstdlib>
using namespace std;
/*���N��4λ����ȫ��ȣ�����һ���������N - N = 0000�������򽫼����ÿһ����һ
���������ֱ��6174��Ϊ����֣������ʽ��������ע��ÿ�����ְ�4λ����ʽ�����

��������1��
6767
�������1��
7766 - 6677 = 1089
9810 - 0189 = 9621
9621 - 1269 = 8352
8532 - 2358 = 6174
��������2��
2222
�������2��
2222 - 2222 = 0000*/




void function(int a, char s[])        //itoa���Լ�д�İ汾������û�а��ַ������µ���
									//��Ϊ�����ĸ����ֿ���������������û��Ҫ������
{										//͵�����þ���
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
}     //�����õã�����Ҫ�ɴ�С��

int change(string & a)
{
	int cnt = 0;
	int res = 0;
	while (cnt<a.size())
	{
		res = res * 10 + a[cnt++] - '0';
	}
	return res;
}  //���ַ������int�ĺ�����������������ַ�����



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
	while (isdigit(c))       //��������ֵľ�push��string��
								//����������־�˵���Ѿ�������
	{
		num.push_back(c);
		cin.get(c);
	}
	if (num[0] == num[1]&&num[0] == num[2]&&num[0] == num[3])   //�ĸ����ʱ���������
	{
		cout << num << " - " << num << " = " << "0000\n";
		//exit(EXIT_FAILURE);
	}
	else
	{
		while (bigger-smaller != 6174)
		{
			while (num.size() < 4)          //Ϊ�ַ�����0.�������4λ������ǰ�油0���������Ҳ�У���������˳��Ҳ����
			{
				num.push_back('0');
			}
			//���򣬲��Ҽ�¼������int��string����¼��intҪ�������string�����淶���
			sort(num.begin(), num.end());
			smaller = change(num); smastr = num;

			//���򣬲��Ҽ�¼������int��string����¼��intҪ�������string�����淶���
			sort(num.begin(), num.end(), cmp);
			bigger = change(num); bigstr = num;

			cout << bigstr << " - "
				<< smastr << " = ";
			
			//������Ϊ����д��int�ֱ���ַ����ĺ���������ֱ�Ӳ�0�����ˡ�����������
			if (bigger - smaller < 10)
				cout << "000";
			else if (bigger - smaller < 100)
				cout << "00";
			else if (bigger - smaller < 1000)
				cout << "0";
			cout<< bigger - smaller << endl;

			function(bigger - smaller, arr);//�ѵ����ֱ���ַ�����������Բ���˳��
			num.erase(num.begin(), num.end());//ɾ����ǰ���ַ���
			num = arr;                    //ֱ��string��c���ַ�����ֵ�����Բ���4λ����Ϊѭ����ʼʱ�Ჹ
		}
	}
	system("pause");
	return 0;
}