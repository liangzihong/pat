/*1023. �����С�� (20)

��������0-9�����ɸ��������������˳��������Щ���֣�������ȫ��ʹ�á�Ŀ����ʹ�����õ�����
������С��ע��0��������λ�������磺��������0������1������5��һ��8�����ǵõ�����С��������10015558��

�ָ������֣����д��������ܹ���ɵ���С������

�����ʽ��

ÿ���������1������������ÿ������������һ���и���10���Ǹ�������˳���ʾ����ӵ������0������1��
��������9�ĸ�������������һ���ո�ָ���10�����ֵ��ܸ���������50��������ӵ��1����0�����֡�

�����ʽ��

��һ��������ܹ���ɵ���С������

����������
2 2 0 0 0 3 0 0 1 0
���������
10015558*/

#include<iostream>
#include<string>
#include<algorithm>
#include<cctype>
using namespace std;

//��һ������ʱ�򿴴��⣬��Ϊ����ľ������֣�����˭֪���ǣ���������Ÿ����֣��ֱ����0-9
//��Ÿ����ֵĸ�����������ʵҲ����

//��һ������ӵ�е����ֶ�����push_bachһ���ַ�����
//�ڶ�����sort�����ҵ�һ����0����С�����������push_back��answer�У�������ַ���Ϊ��a����
//����������sort���򣬴�ʱa������󣬴�ʱ����insert�㷨�������Ѳ����ȥ

//ע�⣺Ҫʱ��ʱ�õ����������������

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