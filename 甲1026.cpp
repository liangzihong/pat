#include<iostream>
#include<algorithm>
#include<queue>
#include<deque>
#include<map>
#include<vector>
#include<cstdio>
#include<cmath>
using namespace std;

//A�������������˷�����
//��һ������ֻҪ����120���ӣ���Ҫ����ѹ����120����
//�ڶ����������ӵ�����û�п��ǵ���� ���С�����Ӵ��꣬����Ŵ�����ӵ�endtime�ֱȱ��С�������磬���ǿͻ�����ʱ������ߴ�
//          ��ʱ�ͻ�Ҫȥ���С�ġ�   �����������޸ģ���ÿ�β����꣬�׸��ͻ���arrivetime�ó�����Ȼ��table�����arrivetimeС��endtime
//			ȫ����Ϊarrivetime����ô�Ϳ��Լ�����ɡ�

//����������:vip�ͻ�����Ҫ��VIP�������Ҫ��Ѫ��Ķ���

//tableҪ���·�Ϊviptable��ordinarytable���ֱ�װvip������ͨ��
//Ȼ��ÿ��ѭ��ʱ  ��  ��һ�����ȿ��ˡ���һ������vip������ͨ
//�����vip���Ϳ����ӣ������������vip���ӻ�����ͨ����
//�������ͨ�ˣ��Ϳ���һ����������ͨ������vip�� �������vip������Ҫ����û�д�������������⣬��һ���ͻ�������
//������ø����ͻ�����VIP��ʱ������ͨ��ʱ����ͬ���Ǿ������߼����С����һ��

//Ȼ�󳣹��������



//���˸�ȥ����A����һ����
//
class Client
{
public:
	int hour;
	int min;
	int second;
	int arrive_time;
	int play_time;
	int isvip;
	int waittime;
	int starttime;
	Client(int hr = 0, int mi = 0, int sec = 0, int play = 0, int isv = 0) {
		hour = hr, min = mi, second = sec, play_time = play * 60, isvip = isv;
		arrive_time = 3600 * hr + 60 * mi + sec;
	}
};

bool cmp(Client&c1, Client&c2)
{
	if (c1.arrive_time < c2.arrive_time) return true;
	else return false;
}

struct Table
{
	int idx;
	int endtime;
	int isvip;
};

bool operator<(Table t1, Table t2)
{
	if (t1.endtime < t2.endtime) return false;
	else if (t1.endtime == t2.endtime&&t1.idx < t2.idx) return false;
	else return true;
}

int main()
{
	int cnt_client;
	cin >> cnt_client;
	vector<Client> ordinary;
	vector<Client> vip;
	
	//��¼vip�ͻ���ordinary�ͻ�
	for (int i = 0; i < cnt_client; i++) {
		int hour, min, second, play_time, isvip;
		scanf("%d:%d:%d %d %d", &hour, &min, &second, &play_time, &isvip);
		if (play_time >= 120) play_time = 120;
		Client newone(hour, min, second, play_time, isvip);
		(isvip == 1) ? vip.push_back(newone) : ordinary.push_back(newone);
	}

	int cnt_table;
	cin >> cnt_table;
	//��¼table
	Table*tables = new Table[cnt_table + 1];
	for (int j = 1; j < cnt_table + 1; j++) {
		tables[j].endtime = 8*3600; tables[j].idx = j; tables[j].isvip = 0;
	}
	
	int cnt_viptable;
	cin >> cnt_viptable;
	for (int j = 0; j < cnt_viptable; j++) {
		int vip_idx;
		cin >> vip_idx;
		tables[vip_idx].isvip = 1;
	}
	//table���������
	int *table_serve = new int[cnt_table + 1];
	fill(table_serve+1, table_serve + cnt_table + 1, 0);
	
	//table�Ķ�
	priority_queue<Table> ordinarytable;
	priority_queue<Table> viptable;

	for (int i = 1; i < cnt_table + 1; i++) {
		if (tables[i].isvip == 0)
			ordinarytable.push(tables[i]);
		else viptable.push(tables[i]);
	}

	sort(ordinary.begin(), ordinary.end(),cmp);
	sort(vip.begin(), vip.end(),cmp);


	//served_client��¼�����˳��
	vector<Client> served_client;
	for (int i = 0; i < cnt_client; i++) {
		Client myturn;
		Table offer;
		
		//ȷ����һ����
		if (vip.size() != 0 && ordinary.size() != 0)
		{
			//vip����
			if (vip[0].arrive_time < ordinary[0].arrive_time) myturn = vip[0], vip.erase(vip.begin());
			//��ͨ������
			else myturn = ordinary[0], ordinary.erase(ordinary.begin());
		}

		else if (vip.size() == 0) myturn = ordinary[0], ordinary.erase(ordinary.begin());
		else if (ordinary.size() == 0) myturn = vip[0], vip.erase(vip.begin());
	
		//��һ������vip�ˣ�������Ҫ��vip�������vip�������У���ȥ��ͨ��
		if (myturn.isvip == 1) {
			if (viptable.top().endtime <= myturn.arrive_time) offer = viptable.top(), viptable.pop();
			
			else if (ordinarytable.top().endtime <= myturn.arrive_time) offer = ordinarytable.top(), ordinarytable.pop();

			else if(viptable.top().endtime <= ordinarytable.top().endtime) offer = viptable.top(), viptable.pop();

			else if (ordinarytable.top().endtime < viptable.top().endtime) offer = ordinarytable.top(), ordinarytable.pop();
		}

		//��һ��������ͨ�ˣ���Ҫ����һ�������ǲ�����ͨ�����Ǿ������������vip������Ҫ��vip�˴��
		else if (myturn.isvip == 0)
		{
			//��һ����vip��
			if (viptable.top().endtime <= ordinarytable.top().endtime) {
				/*����ֻ����top��û��pop    *************/
				offer = viptable.top();
				//��vip���
				if (vip.size() != 0 && vip[0].arrive_time <= offer.endtime) {
					viptable.pop();
					ordinary.push_back(myturn);
					sort(ordinary.begin(), ordinary.end(), cmp);
					myturn = vip[0], vip.erase(vip.begin());
				}
				else {
					//���˼⣬��ͨ�˾�Ҫ����С��ŵ��Ǹ�.
					//�����ͨ����vip��ʱ����ͬ������С���
					if (ordinarytable.top().endtime == offer.endtime&&ordinarytable.top().idx < offer.idx)
						offer = ordinarytable.top(), ordinarytable.pop();
					else viptable.pop();
				}
			}
			//��һ������ͨ��
			else if(ordinarytable.top().endtime < viptable.top().endtime) offer = ordinarytable.top(), ordinarytable.pop();
		}
		
		if (offer.endtime >= 21 * 3600) break;


		table_serve[offer.idx]++;
		//table��ʱ�䣬����
		//����ͻ���������ӿ죬Ҫ�ȣ�����endtime��endtime+play_time;
		if (offer.endtime >= myturn.arrive_time) {
			myturn.waittime = offer.endtime - myturn.arrive_time;
			myturn.starttime = offer.endtime;
			offer.endtime = offer.endtime + myturn.play_time;
		}
		//�ͻ�����������������õȴ���endtime�ǿͻ�arrivetime+playtime
		else if (offer.endtime < myturn.arrive_time) {
			myturn.waittime = 0;
			myturn.starttime = myturn.arrive_time;
			offer.endtime = myturn.arrive_time + myturn.play_time;
		}
	
		served_client.push_back(myturn);
		offer.isvip == 1 ? viptable.push(offer) : ordinarytable.push(offer);
	
		
		if (i + 1 == cnt_client) break;

		int mintime;
		vector<Table> temprestore;
		if (vip.size() != 0 && ordinary.size() != 0) {
			if (vip[0].arrive_time < ordinary[0].arrive_time) mintime = vip[0].arrive_time;
			else mintime = ordinary[0].arrive_time;
		}
		else if (vip.size() == 0) mintime = ordinary[0].arrive_time;
		else if (ordinary.size() == 0) mintime = vip[0].arrive_time;

		while (ordinarytable.size() != 0) {
			Table temp = ordinarytable.top();
			ordinarytable.pop();
			if (temp.endtime < mintime) temp.endtime = mintime;
			temprestore.push_back(temp);
		}

		while (temprestore.size() != 0) {
			ordinarytable.push(temprestore[0]);
			temprestore.erase(temprestore.begin());
		}

		while (viptable.size() != 0) {
			Table temp = viptable.top();
			viptable.pop();
			if (temp.endtime < mintime) temp.endtime = mintime;
			temprestore.push_back(temp);
		}

		while (temprestore.size() != 0) {
			viptable.push(temprestore[0]);
			temprestore.erase(temprestore.begin());
		}
	}

	for (int i = 0; i < served_client.size(); i++) {
		int arr = served_client[i].arrive_time;
		int start = served_client[i].starttime;
		int wait = served_client[i].waittime;
		printf("%02d:%02d:%02d %02d:%02d:%02d %.0f\n", arr / 3600
			, (arr % 3600) / 60, arr % 60, start / 3600, (start % 3600) / 60, start % 60,
			round(served_client[i].waittime / 60.0));
	}

	for (int i = 1; i < cnt_table + 1; i++) {
		cout << table_serve[i];
		if (i != cnt_table) cout << " ";
	}

	system("pause");
	return 0;
}