#include<cstdio>
#include<string>
#include<sstream>
#include<iostream>
#include<stack>
#include<deque>
using namespace std;

//��ʵ�ܼ򵥣���������û�г�����
//�����û�����������ǣ�������������ǰ��ʼ����ô������ִ�С�


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
	client *clients = new client[clientnum+1];   //clientsΪ�ͻ�����

	for (int i = 1; i <= clientnum; i++)  //����ͻ�����Ҫ��ʱ��
	{
		cin >> clients[i].needtime; 
		clients[i].id = i;
		wait.push_back(clients[i]); 
	}
	
	int *asked = new int[asknum];  //ѯ�ʵĿͻ���num
	
	for (int i = 0; i < asknum; i++) 
		cin >> asked[i];

	window *windows = new window[winnum+1];
	for (int i = 1; i <= winnum; i++)
		windows[i].maxnum = linenum;

	//û��ʼ����ʱ��������winnum*linenum���ͻ��ڴ���ǰ�ȴ���Ҫô������Ҫô������
	for (int i = 1; i <=clientnum; i++)
	{
		if (i <= winnum*linenum) 
		{
			int j = ((i%winnum == 0) ? winnum : i%winnum);  //����ĸ����ڣ���ô�ĵı��������ģ���������%4
			windows[j].add(wait.front());
			wait.pop_front();
		}
		else break;
	}






	for (int k = 480; k <17*60; k++)
	{
		//ÿһ���Ӷ���ÿһ�����ڵĵ�һ���ͻ���һ������
		for (int i = 1; i <= winnum; i++)
		{
			if (windows[i].isempty() == 1)
				continue;    //���Ϊ���ڿգ�������
			if (windows[i].single.front().endtime == 480)
				windows[i].single.front().endtime = k;

			//�׿ͻ���neddʱ��--��endʱ��++��
			int time=--windows[i].single.front().needtime;
			windows[i].single.front().endtime++;

			//����׿ͻ�ʱ�����꣬���а�clients����dealoutput������Ȼ���clients������Ӧ�Ĵ���
			//Ȼ�����wait���в�Ϊ�գ������������� 
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

	//�ڴ���ͷһ���ģ����endtime��Ϊ480��û�п�ʼ���񣩣���Ϊһ������endtime�൱�ڵ�ǰʱ�䣬ÿһ�ζ���䶯
	//��ô��Щ����Ҳ���Լ�����ɡ�
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
