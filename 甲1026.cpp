#include<iostream>
#include<algorithm>
#include<queue>
#include<deque>
#include<map>
#include<vector>
#include<cstdio>
#include<cmath>
using namespace std;

//A不出来，放弃了放弃了
//第一个错误：只要大于120分钟，就要将它压缩到120分钟
//第二个错误：桌子的排序没有考虑到如果 标号小的桌子打完，而标号大的桌子的endtime又比标号小的桌子早，但是客户来的时间比两者大
//          此时客户要去标号小的。   所以我做了修改，将每次操作完，首个客户的arrivetime拿出来，然后将table里面比arrivetime小的endtime
//			全部置为arrivetime，那么就可以继续完成。

//第三个错误:vip客户优先要与VIP桌，这就要换血大改动了

//table要重新分为viptable和ordinarytable，分别装vip桌和普通桌
//然后每次循环时  ，  第一步是先看人。第一个人是vip还是普通
//如果是vip，就看桌子，分情况讨论是vip桌子还是普通桌子
//如果是普通人，就看第一张桌子是普通桌还是vip桌 ，如果是vip桌，就要看有没有打尖的情况，如果打尖，第一个客户更换。
//如果不用更换客户，且VIP桌时间与普通桌时间相同，那就找两者间序号小的那一个

//然后常规操作即可



//我了个去终于A了这一题了
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
	
	//记录vip客户和ordinary客户
	for (int i = 0; i < cnt_client; i++) {
		int hour, min, second, play_time, isvip;
		scanf("%d:%d:%d %d %d", &hour, &min, &second, &play_time, &isvip);
		if (play_time >= 120) play_time = 120;
		Client newone(hour, min, second, play_time, isvip);
		(isvip == 1) ? vip.push_back(newone) : ordinary.push_back(newone);
	}

	int cnt_table;
	cin >> cnt_table;
	//记录table
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
	//table服务的人数
	int *table_serve = new int[cnt_table + 1];
	fill(table_serve+1, table_serve + cnt_table + 1, 0);
	
	//table的堆
	priority_queue<Table> ordinarytable;
	priority_queue<Table> viptable;

	for (int i = 1; i < cnt_table + 1; i++) {
		if (tables[i].isvip == 0)
			ordinarytable.push(tables[i]);
		else viptable.push(tables[i]);
	}

	sort(ordinary.begin(), ordinary.end(),cmp);
	sort(vip.begin(), vip.end(),cmp);


	//served_client记录服务的顺序
	vector<Client> served_client;
	for (int i = 0; i < cnt_client; i++) {
		Client myturn;
		Table offer;
		
		//确定第一个人
		if (vip.size() != 0 && ordinary.size() != 0)
		{
			//vip早来
			if (vip[0].arrive_time < ordinary[0].arrive_time) myturn = vip[0], vip.erase(vip.begin());
			//普通人早来
			else myturn = ordinary[0], ordinary.erase(ordinary.begin());
		}

		else if (vip.size() == 0) myturn = ordinary[0], ordinary.erase(ordinary.begin());
		else if (ordinary.size() == 0) myturn = vip[0], vip.erase(vip.begin());
	
		//第一个人是vip人，则首先要找vip桌；如果vip桌不空闲，就去普通桌
		if (myturn.isvip == 1) {
			if (viptable.top().endtime <= myturn.arrive_time) offer = viptable.top(), viptable.pop();
			
			else if (ordinarytable.top().endtime <= myturn.arrive_time) offer = ordinarytable.top(), ordinarytable.pop();

			else if(viptable.top().endtime <= ordinarytable.top().endtime) offer = viptable.top(), viptable.pop();

			else if (ordinarytable.top().endtime < viptable.top().endtime) offer = ordinarytable.top(), ordinarytable.pop();
		}

		//第一个人是普通人，就要看第一张桌子是不是普通桌，是就正常；如果是vip桌，就要找vip人打尖
		else if (myturn.isvip == 0)
		{
			//第一张是vip桌
			if (viptable.top().endtime <= ordinarytable.top().endtime) {
				/*这里只用了top，没有pop    *************/
				offer = viptable.top();
				//有vip打尖
				if (vip.size() != 0 && vip[0].arrive_time <= offer.endtime) {
					viptable.pop();
					ordinary.push_back(myturn);
					sort(ordinary.begin(), ordinary.end(), cmp);
					myturn = vip[0], vip.erase(vip.begin());
				}
				else {
					//打不了尖，普通人就要找最小标号的那个.
					//如果普通桌和vip桌时间相同，找最小标号
					if (ordinarytable.top().endtime == offer.endtime&&ordinarytable.top().idx < offer.idx)
						offer = ordinarytable.top(), ordinarytable.pop();
					else viptable.pop();
				}
			}
			//第一张是普通桌
			else if(ordinarytable.top().endtime < viptable.top().endtime) offer = ordinarytable.top(), ordinarytable.pop();
		}
		
		if (offer.endtime >= 21 * 3600) break;


		table_serve[offer.idx]++;
		//table换时间，进堆
		//如果客户到达比桌子快，要等，桌子endtime是endtime+play_time;
		if (offer.endtime >= myturn.arrive_time) {
			myturn.waittime = offer.endtime - myturn.arrive_time;
			myturn.starttime = offer.endtime;
			offer.endtime = offer.endtime + myturn.play_time;
		}
		//客户到达比桌子慢，不用等待，endtime是客户arrivetime+playtime
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