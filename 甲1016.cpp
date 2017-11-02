#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstdio>
using namespace std;
//������ô�00:00 : 00��dd : hh : mm������Ա����������⣬����01 : 12 : 00��02 : 02 : 00���������д���
//1���������⡣
//2��ͬСʱ���⡣
class call
{
public:
	string name;
	string state;
	int month;
	int day;
	int hour;
	int min;
	call()
	{
		name = state = "";
		month = day = hour = min = 0;
	}
	
};

bool cmp(call c1, call c2)
{
	if (c1.name < c2.name)
		return true;
	else if (c1.name == c2.name)
	{
		if (c1.month < c2.month)
			return true;
		else if (c1.month == c2.month&&c1.day < c2.day) return true;
		else if (c1.month == c2.month&&c1.day == c2.day
			&&c1.hour * 60 + c1.min < c2.hour * 60 + c2.min)
			return true;
		else return false;
	}
	else return false;
}

vector<call> analyse(call calls[], int cnt)
{
	vector<call>*pairs = new vector<call>;
	for (int i = 0; i < cnt - 1; i++)
	{
		if (calls[i].state == "on-line"&&calls[i + 1].state == "off-line"
			&&calls[i].name == calls[i + 1].name)
			pairs->push_back(calls[i]), pairs->push_back(calls[i + 1]);
	}
	return *pairs;
}

//price�Ǵ�0��23���ȽϺ�
double function(call a, call b, double price[])
{
	int day1 = a.day, hour1 = a.hour, min1 = a.min;
	int day2 = b.day, hour2 = b.hour, min2 = b.min;

	double allmoney = 0;
	int allmin = 0;
	
	//����һ��ʧ����룬��Ϊ��������hour��һ���Ļ��������һ��������롣
	//��ȷ�ķ���Ӧ����   ��ȫ����ת����01��00��00���Ǹ�ʱ��
	//Ȼ����������͵õ����մ𰸡�
	/*if (day1 == day2)
	{
		if(hou1==hou2)
		{
			allmoney=(min2-min1)*price[hour1];
			allmin=min2-min1;
		}
		else{
		allmoney = (60.0 - min1)*price[hour1]+(min2)*price[hour2];
		for (int i = hour1 + 1; i < hour2; i++)
		{
			allmoney =allmoney+ 60 * price[i];
			allmin += 60;
		}
		allmin =allmin+ 60 - min1 + min2;
	}}*/


		//һ���ײ�Ϊdaymeal
		double daymeal = 0;
		for (int i = 0; i < 24; i++)
			daymeal += 60 * price[i];
		

		double money1 = daymeal*(day1-1);
		int allmin1 = 60 * 24 * day1;

		for (int i = 0; i < hour1; i++)
		{
			money1 = money1 + 60 * price[i];
			allmin1 = allmin1 + 60 ;
		}
		    
		money1 = money1 + price[hour1] * min1;
		allmin1 = allmin1 + min1;

		double money2 = daymeal*(day2-1);
		int allmin2 = 60 * 24 * day2;

		for (int i = 0; i < hour2; i++)
		{
			money2 = money2 + 60 * price[i];
			allmin2 = allmin2 + 60;
		}

		money2 = money2 + price[hour2] * min2;
		allmin2 = allmin2 + min2;

		allmoney = money2 - money1;
		allmin = allmin2 - allmin1;
	printf("%d $%.2lf\n", allmin, allmoney);
	return allmoney;
}


int main()
{
	char *tishen = new char[100];
	//�����ֱ����Ԫ
	double price[24];
	for (int i = 0; i < 24; i++)
		scanf("%lf", &price[i]), price[i] = price[i] / 100.0;
	int cntcall;
	scanf("%d", &cntcall);
	call*calls = new call[cntcall];
	//������е���Ϣ
	for (int i = 0; i < cntcall; i++)
	{
		scanf("%s", tishen); calls[i].name = tishen;
		scanf("%d:%d:%d:%d", &calls[i].month, &calls[i].day, &calls[i].hour, &calls[i].min);
		scanf("%s", tishen); calls[i].state = tishen;
	}

	//�Ժ��е���Ϣ���������Ȱ������ţ��ٰ�ʱ���š������Ļ������ǰһ����on-line��һ����off-line����������ͬ
	//�Ϳ���˵��һ����һ������
	sort(&calls[0], &calls[cntcall], cmp);

	//���pairsװ���˺ϸ�ĺ���
	vector<call> pairs;
	pairs = analyse(calls, cntcall);
	if (pairs.size() == 0)
		return 0;
	//��Ϊ�϶���һ�Է��ϣ������Ȱ���һ�Ը���ȥ
	string thisname = pairs[0].name;
	double total = 0;
	printf("%s %02d\n", pairs[0].name.c_str(), pairs[0].month);

	for (int i = 0; i <= pairs.size(); i = i + 2)
	{
		//���������һ��i��=pairs��size��������Ϊ��i==pairs.size()����ô����֤��ǰһ���Ѿ���ᣬ������ܽ�
		if (i >= pairs.size())
		{
			printf("Total amount: $%.2lf\n", total);
			break;
		}

		//�����������һ�ڵ�������ͬ����ô���Լ������
		if (pairs[i].name == thisname)
			printf("%02d:%02d:%02d %02d:%02d:%02d ", pairs[i].day, pairs[i].hour, pairs[i].min,
				pairs[i + 1].day, pairs[i + 1].hour, pairs[i + 1].min);

		//���������ͬ��֤������һ���Ѿ���ᣬ���������β������0������ʼ��һ��
		else
		{
			printf("Total amount: $%.2lf\n", total);
			thisname = pairs[i].name;
			total = 0;
			printf("%s %02d\n", pairs[i].name.c_str(), pairs[i].month);
			printf("%02d:%02d:%02d %02d:%02d:%02d ", pairs[i].day, pairs[i].hour, pairs[i].min,
				pairs[i + 1].day, pairs[i + 1].hour, pairs[i + 1].min);

		}
		//printf("%02d:%2d:%02d %02d:%02d:%02d\n", pairs[i].day, pairs[i].hour, pairs[i].min,
		//	pairs[i + 1].day, pairs[i + 1].hour, pairs[i + 1].min);
		total = total + function(pairs[i], pairs[i + 1], price);
	}

	system("pause");
	return 0;
}


