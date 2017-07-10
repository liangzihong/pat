#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstdio>
#include<cstdlib>
using namespace std;

int hege;
int good;

typedef struct aaa
{
	string num;
	int demark;
	int caimark;
}Node;

bool cmp(Node&a, Node&b)         //尝试一下只考虑一边行不行得通
{
	if (a.caimark >= good&&a.demark >= good&&                    //a为第一类,b为第一类
		b.caimark >= good&&b.demark >= good)
	{
		if (a.caimark + a.demark > b.caimark + b.demark) return true;
		else if ((a.caimark + a.demark == b.caimark + b.demark)&&a.demark > b.demark) return true;
		else if ((a.caimark + a.demark == b.caimark + b.demark) && a.demark == b.demark&&a.num<b.num) return true;
		else return false;
	}

	if (a.caimark >= good&&a.demark >= good)   
	{
		if (b.caimark < good || b.demark < good) return true;         //b为非第一类
	}




	if (a.caimark < good&&a.demark >= good)                                //a为第二类
	{
		if (b.caimark >= good&&b.demark >= good)                            //b为第一类
		{
			return false;
		}
		else if (b.caimark < good&&b.demark >= good)                             //b为第二类
		{
			if (a.caimark + a.demark > b.caimark + b.demark) return true;
			else if ((a.caimark + a.demark == b.caimark + b.demark) && a.demark > b.demark) return true;
			else if ((a.caimark + a.demark == b.caimark + b.demark) && a.demark==b.demark&&a.num < b.num) return true;
			else return false;
		}
		else return true;                                                //b为非第一第二
		
	}



	if (a.caimark < good&&a.demark < good&&a.demark>=a.caimark)                   //a为第三类
	{
		if (b.caimark >= good&&b.demark >= good)                            //b为第一类
		{
			return false;
		}
		else if (b.caimark < good&&b.demark >= good)                             //b为第二类
		{
			return false;
		}
		else if (b.caimark < good&&b.demark < good&&b.demark >= b.caimark)      //b为第三类
		{
			if (a.caimark + a.demark > b.caimark + b.demark) return true;
			else if (a.demark + a.caimark == b.demark + b.caimark&&a.demark > b.demark) return true;
			else if (a.demark + a.caimark == b.demark + b.caimark&&a.demark==b.demark&&a.num < b.num) return true;
			else return false;
		}
		else
		{
			return true;                                                //b为非一二三
		}
	}

	else                      //a为第四类
	{
		if (b.caimark >= good&&b.demark >= good)                            //b为第一类
		{
			return false;
		}
		else if (b.caimark < good&&b.demark >= good)                             //b为第二类
		{
			return false;
		}
		else if (b.caimark < good&&b.demark < good&&b.demark >= b.caimark)      //b为第三类
		{
			return false;
		}
		else
		{
			if (a.caimark + a.demark > b.caimark + b.demark) return true;
			else if (a.demark + a.caimark == b.demark + b.caimark&&a.demark > b.demark) return true;
			else if (a.demark + a.caimark == b.demark + b.caimark&&a.demark == b.demark&&a.num < b.num) return true;
			else return false;
		}
	}

}
int main()
{
	int N;
	cin >> N;
	vector<Node> arr;      //创建N个Node的动态数组

	cin >> hege;          //最低录取分数线
	cin >> good;        //优先录取分数线

	int cnt = 0;//合格人数
	Node fucktemp;
	for (int i = 0; i < N; i++)
	{
		char temp[20];
		int detemp; int caitemp;
		//cin >> temp >> detemp >> caitemp;

		scanf("%s %d %d", temp, &detemp, &caitemp);
		
		if (detemp >= hege&&caitemp >= hege)
		{
			fucktemp.num = temp;
			fucktemp.demark = detemp;
			fucktemp.caimark = caitemp;
			cnt++;
			arr.push_back(fucktemp);
		}
	}

	sort(arr.begin(), arr.end(),cmp);

	cout << cnt << endl;
	vector<Node>::iterator it;
	for (it=arr.begin();it!=arr.end();it++)
	{
		/*cout << arr[i].num << " "
			<< arr[i].demark << " "
			<< arr[i].caimark << endl;*/
		printf("%s %d %d\n", (*it).num.c_str(), (*it).demark, (*it).caimark);
	}
	//system("pause");
	return 0;
}