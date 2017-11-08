#include<iostream>
#include<vector>
#include<algorithm>
#include<deque>
#include<set>
#include<cstdio>
using namespace std;

//����:��ʵ����֪ʶ��©��
//����һ����ͨ����+dfs���������

//��ʵ����һ�������ֱ�����⣬��һ����dfs����������ĵ�push��answer���Լ����÷ţ�����ʱ����Щ������ֱ����һͷ
//Ȼ���maxlen=0��answer����set�в���գ���answer������һ���㣨���ǵ�һ���㣩����dfs�������õ������Щ�㣬�зŽ�answer��

//��ʱ���ٰ�answer����set����ô����Щ�������ֱ��ͷβ

//����ͨ�������⣬ѧ����filled���÷���

int maxlen = 0;
vector<int> answer;
vector<int> path;


void bfs(vector< vector<int> >matrix, int idx)
{
	int cnt = matrix.size() - 1;
	int*isfound = new int[cnt + 1];
	int*distance = new int[cnt + 1];
	for (int i = 1; i < cnt + 1; i++)
		isfound[i] = 0, distance[i] = 0;


	deque<int> line;
	distance[idx] = 1;
	line.push_back(idx);
	while (line.empty() == 0) {
		int k = line.front();
		line.pop_front();
		isfound[k] = 1;


		if (matrix[k].size() == 1 && k != idx)
		{
			if (distance[k] > maxlen)
				maxlen = distance[k], answer.clear(), answer.push_back(k);
			else if (distance[k] == maxlen)
				 answer.push_back(k);
			continue;
		}


		vector<int> kpoint = matrix[k];
		for (int j = 0; j < kpoint.size(); j++) {
			int i = kpoint[j];
			if (isfound[i] == 0) {
				distance[i] = distance[k] + 1;
				line.push_back(i);
			}
		}
	}
	delete[]isfound;
	delete[]distance;



}




//����ͨ����
int countconnected(vector< vector<int> > matrix, int cnt)
{
	int num_connected = 0;
	int *isfound = new int[cnt + 1];
	for (int i = 1; i < cnt + 1; i++)
		isfound[i] = 0;

	//��kΪ���ڵ㲻�Ͻ��й�����ȱ���
	int first;
	deque<int> line;
	for (int i = 1; i < cnt + 1; i++) {
		if (isfound[i] == 0)	num_connected++, first = i;
		line.push_back(first);

		while (line.size() != 0) {
			int k = line.front();
			line.pop_front();
			isfound[k] = 1;

			vector<int> kpoint = matrix[k];
			for (int j = 0; j < kpoint.size(); j++)
				//������ȣ����û��̽Ѱ��
				if (isfound[kpoint[j]] == 0)
					line.push_back(kpoint[j]);
		}

	}
	delete[]isfound;
	return num_connected;

}

int main()
{
	int cnt;
	cin >> cnt;
	if (cnt == 1) {
		cout << 1 << endl;
		return 0;
	}
	vector< vector<int> > matrix(cnt + 1);

	for (int i = 0; i < cnt - 1; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		matrix[a].push_back(b);
		matrix[b].push_back(a);
	}


	//����ͨ����
	int num_connected = countconnected(matrix, cnt);

	if (num_connected != 1) {
		cout << "Error: " << num_connected << " components";
		return 0;
	}


	vector<int> degreeis1;
	for (int i = 1; i < cnt + 1; i++) {
		if (matrix[i].size() == 1)
			degreeis1.push_back(i);
	}

	bfs(matrix, 1);
	vector<int> xxx;
	set<int> restore;
	vector<int>::iterator it = answer.begin(); //����ǰ������� 
	int s1 = degreeis1[0];

	for (; it != answer.end(); it++) {
		restore.insert(*it);
	}
	for (int i = 0; i < answer.size(); i++)
		if (answer[i] != 1) { s1 = answer[i]; break; }
	
	maxlen = 0;
	answer.clear();
	bfs(matrix, s1);
	for (it = answer.begin(); it != answer.end(); it++)
		restore.insert(*it);
	
	for (set<int>::iterator setit = restore.begin(); setit != restore.end(); setit++) {
		xxx.push_back(*setit);
	}
	sort(xxx.begin(), xxx.end());
	for (int j = 0; j < xxx.size(); j++)
		printf("%d\n", xxx[j]);
	return 0;

}