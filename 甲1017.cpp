#include<iostream>
#include<cstdio>
#include<string>
#include<deque>
#include<queue>
#include<algorithm>
using namespace std;

//Ҫ�õ����ȶ��е��÷�����   queue�е� priority_queue�������кܶණ��Ҫע�⣬Ĭ����  ����
//�������Ҫ��С�ѣ���Ҫ����һ��<����������ҵ�����>�������д����������

//������������������������ǰ�������㶼���Ա������������Ĳ������������


class client
{
public:
	int arrive;
	int need;
	int end;
};

//��ΪҪ������С�ѣ���������<�ĺ�������Ҫ��ת���������ý���ʱ������Ϊ�Ƚ�
bool operator<(client a, client b)
{
	return a.end > b.end;
}

//���ǿͻ����Ŷ�ʱ�䣬����ԽС����Խ�磬��������ǰ��
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

	//����ã�������ʱ��
	sort(clients, clients + cntclient, cmp);

	//Ȼ������ŶӶ�������
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