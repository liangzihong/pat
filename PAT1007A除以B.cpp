#include<iostream>
#include<vector>
#include<string>
using namespace std;



//˼·��ֱ������ʽ����������
//Ϊ����Ӧstl����������STL���vector������������push_back(),����vector��int������iterator��Ϊ������
//Ȼ�����С��num�ģ����ڴ���+0�����ҽ���һ������ֵΪ10**it+*��it+1����
//Ȼ�������ʱ�򣬾ʹӵ�һ������0������ʼ��������ȫ����Ϊ0�������0��


int main()
{
	vector<int> arr;
	vector<int> answer;

	string bignum;
	cin >> bignum;
	int num;
	cin >> num;
	int temp;
	int yushu;    //����
	int zhengshu; //����

	for (int i = 0; i<bignum.size(); i++)
	{
		arr.push_back(int(bignum[i] - 48));
	}

	vector<int>::iterator it;
	for (it = arr.begin(); it != arr.end()-1; it++)
	{
		if (*it < num)
		{
			/*temp = *it*10+*(it + 1);
			yushu = temp%num;
			zhengshu = temp / num;
			answer.push_back(zhengshu);
			*(it + 1) = yushu;*/
			
			answer.push_back(0);
			*(it + 1) = *it * 10 + *(it + 1);
		}
		else
		{
			zhengshu = *it / num;
			yushu = *it%num;
			answer.push_back(zhengshu);
			*(it + 1) = yushu * 10 + *(it + 1);
		}
	}

	zhengshu = *it / num;
	yushu = *it % num;
	answer.push_back(zhengshu);

	int state = 0;  //Ҫ�ӵ�һ������0�����ֿ�ʼ���;
	for (it = answer.begin(); it != answer.end(); it++)
	{
		if (it == answer.end() - 1 && state == 0)         //���ȫ����Ϊ0������Ҫ���0;
		{
			cout << *it;
		}
		if (*it == 0&&state==0)
		{
			continue;
		}

		state = 1;
		cout << *it;
	}
	cout << " "<<yushu;

	system("pause");
	return 0;
}