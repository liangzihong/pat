#include<cstdio>
#include<string>
#include<sstream>
#include<iostream>
#include<stack>
#include<deque>
using namespace std;

//其实很简单，但是题意没有充分理解
//这里的没有理解的题意是：如果服务在五点前开始，那么照样能执行。


class client
{
public:
	int endtime;
	int needtime;
	string output;
	int id;
	client()
	{
		endtime = 480;
		needtime = 0;
		output = "Sorry";
		id = 0;
	}
	void dealoutput()
	{
		output = "";
		int hour = endtime / 60;
		int min = endtime % 60;
		char temp[10];
		sprintf(temp, "%02d", hour);
		output += temp;
		output += ":";
		sprintf(temp, "%02d", min);
		output += temp;
	
	}
};

class window
{
public:
	int maxnum;
	deque<client> single;
	window()
	{}
	int isempty()
	{
		if (single.size() == 0)
			return 1;
		else return 0;
	}
	void add(client a)
	{
		single.push_back(a);
	}
};


int main()
{
	int winnum, linenum, clientnum, asknum;
	deque<client> wait;
	cin >> winnum >> linenum >> clientnum >> asknum;
	client *clients = new client[clientnum+1];   //clients为客户数组

	for (int i = 1; i <= clientnum; i++)  //输入客户的需要的时间
	{
		cin >> clients[i].needtime; 
		clients[i].id = i;
		wait.push_back(clients[i]); 
	}
	
	int *asked = new int[asknum];  //询问的客户的num
	
	for (int i = 0; i < asknum; i++) 
		cin >> asked[i];

	window *windows = new window[winnum+1];
	for (int i = 1; i <= winnum; i++)
		windows[i].maxnum = linenum;

	//没开始工作时，可以有winnum*linenum个客户在窗口前等待。要么塞满，要么不够。
	for (int i = 1; i <=clientnum; i++)
	{
		if (i <= winnum*linenum) 
		{
			int j = ((i%winnum == 0) ? winnum : i%winnum);  //如果四个窗口，那么四的倍数都在四，其他都是%4
			windows[j].add(wait.front());
			wait.pop_front();
		}
		else break;
	}






	for (int k = 480; k <17*60; k++)
	{
		//每一分钟都对每一个窗口的第一个客户来一个操作
		for (int i = 1; i <= winnum; i++)
		{
			if (windows[i].isempty() == 1)
				continue;    //如果为窗口空，则跳过
			if (windows[i].single.front().endtime == 480)
				windows[i].single.front().endtime = k;

			//首客户的nedd时间--，end时间++；
			int time=--windows[i].single.front().needtime;
			windows[i].single.front().endtime++;

			//如果首客户时间用完，进行把clients调用dealoutput函数，然后把clients【】对应的带入
			//然后如果wait队列不为空，可以立即加入 
			if (time == 0) 
			{
				client temp=windows[i].single.front();
				temp.dealoutput();
				windows[i].single.pop_front();
				clients[temp.id] = temp;

				if (wait.empty() == false)
				{
					windows[i].add(wait.front());
					wait.pop_front();
				}
			}

		}
	}

	//在窗口头一个的，如果endtime不为480（没有开始服务），因为一旦服务，endtime相当于当前时间，每一次都会变动
	//那么这些服务也可以继续完成。
	for (int i = 1; i <= winnum; i++)
	{
		if (windows[i].isempty() == 1) continue;
		client temp = windows[i].single.front();
		if (temp.endtime != 480) {
			temp.endtime += temp.needtime;
			temp.dealoutput();
			clients[temp.id] = temp;
		}
	}




	for (int i = 0; i < asknum; i++)
	{
		cout << clients[asked[i]].output << endl;
	}

	system("pause");
	return 0;

}
