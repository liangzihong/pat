#include<iostream>
#include<cstdio>
#include<string>
#include<deque>
#include<queue>
#include<algorithm>
using namespace std;

//要用到优先队列的用法，即   queue中的 priority_queue，并且有很多东西要注意，默认是  最大堆
//如果你想要最小堆，就要重载一个<运算符，并且当它是>运算符来写函数，即可

//错误：它这里题意是如果你五点前来到，你都可以被服务，五点后来的不算入服务人数


class client
{
public:
	int arrive;
	int need;
	int end;
};

//因为要调用最小堆，所以重载<的函数返回要调转，而且是用结束时间来作为比较
bool operator<(client a, client b)
{
	return a.end > b.end;
}

//这是客户的排队时间，所以越小，就越早，就在数组前面
bool cmp(client a, client b)
{
	if (a.arrive < b.arrive) return true;
	else return false;
}


int main()
{
	int cntclient, winnum;
	cin >> cntclient >> winnum;
	client*clients = new client[cntclient];
	deque<client> line;
	int wait_time = 0;

	for (int i = 0; i < cntclient; i++)
	{
		int hour, min, second;
		scanf("%d:%d:%d", &hour, &min, &second);
		clients[i].arrive = 3600 * hour + 60 * min + second;

		cin >> min;
		clients[i].need = 60 * min;
	}

	//排序好，按来的时间
	sort(clients, clients + cntclient, cmp);

	//然后放在排队对列里面
	for (int i = 0; i < cntclient; i++)
		line.push_back(clients[i]);

	priority_queue<client> windows;
	int served = 0;
	for (int i = 0; i < winnum; i++)
	{
		client a;
		a.end = 8 * 3600;
		windows.push(a);
	}
	while (line.size() != 0)
	{
		client first = windows.top();
		//cout << first.end << "   ";
		/*if (first.end > 17 * 3600)
		{
			break;
		}*/
 		client temp = line.front();
		line.pop_front();
		if(temp.arrive<=17*3600)
			served++;
		else break;
		windows.pop();
		
		if (temp.arrive >= first.end) {
			client a;
			a.end = temp.arrive + temp.need;
			windows.push(a);
		}
		
		else {
			wait_time = wait_time + first.end - temp.arrive;
			client a;
			a.end = first.end + temp.need;
			windows.push(a);
		}
	}
	printf("%.1lf\n", wait_time*1.0 / served/60);
	system("pause");
	return 0;
}