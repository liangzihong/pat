#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstdio>
using namespace std;
//计算费用从00:00 : 00到dd : hh : mm计算可以避免跨天的问题，比如01 : 12 : 00到02 : 02 : 00，避免所有错误
//1、隔天问题。
//2、同小时问题。
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

//price是从0到23数比较好
double function(call a, call b, double price[])
{
	int day1 = a.day, hour1 = a.hour, min1 = a.min;
	int day2 = b.day, hour2 = b.hour, min2 = b.min;

	double allmoney = 0;
	int allmin = 0;
	
	//这是一段失误代码，因为如果大家连hour都一样的话，这就是一个错误代码。
	//正确的方法应该是   把全部都转化成01：00：00到那个时间
	//然后两者相减就得到最终答案。
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


		//一天套餐为daymeal
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
	//把美分变成美元
	double price[24];
	for (int i = 0; i < 24; i++)
		scanf("%lf", &price[i]), price[i] = price[i] / 100.0;
	int cntcall;
	scanf("%d", &cntcall);
	call*calls = new call[cntcall];
	//输入呼叫的信息
	for (int i = 0; i < cntcall; i++)
	{
		scanf("%s", tishen); calls[i].name = tishen;
		scanf("%d:%d:%d:%d", &calls[i].month, &calls[i].day, &calls[i].hour, &calls[i].min);
		scanf("%s", tishen); calls[i].state = tishen;
	}

	//对呼叫的信息进行排序，先按姓名排，再按时间排。这样的话，如果前一个是on-line后一个是off-line并且姓名相同
	//就可以说这一对是一个呼叫
	sort(&calls[0], &calls[cntcall], cmp);

	//这个pairs装载了合格的呼叫
	vector<call> pairs;
	pairs = analyse(calls, cntcall);
	if (pairs.size() == 0)
		return 0;
	//因为肯定有一对符合，所以先把这一对搞上去
	string thisname = pairs[0].name;
	double total = 0;
	printf("%s %02d\n", pairs[0].name.c_str(), pairs[0].month);

	for (int i = 0; i <= pairs.size(); i = i + 2)
	{
		//这里故意有一个i《=pairs。size（），因为，i==pairs.size()，那么可以证明前一个已经完结，就输出总金额。
		if (i >= pairs.size())
		{
			printf("Total amount: $%.2lf\n", total);
			break;
		}

		//如果姓名与这一期的姓名相同，那么可以继续输出
		if (pairs[i].name == thisname)
			printf("%02d:%02d:%02d %02d:%02d:%02d ", pairs[i].day, pairs[i].hour, pairs[i].min,
				pairs[i + 1].day, pairs[i + 1].hour, pairs[i + 1].min);

		//如果姓名不同，证明了上一期已经完结，可以输出结尾，并清0，并开始下一个
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


