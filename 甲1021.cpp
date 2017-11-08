#include<iostream>
#include<vector>
#include<algorithm>
#include<deque>
#include<set>
#include<cstdio>
using namespace std;

//错误:其实这是知识的漏洞
//这是一题连通分量+dfs解决的问题

//其实这是一个树的最长直径问题，从一个点dfs遍历，把最长的点push进answer（自己不用放），此时，这些点就在最长直径的一头
//然后把maxlen=0，answer放入set中并清空，对answer的其中一个点（不是第一个点）进行dfs遍历，得到最长的那些点，有放进answer中

//此时，再把answer放入set，那么，这些就是最长的直径头尾

//不过通过这套题，学会了filled的用法。

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




//数连通分量
int countconnected(vector< vector<int> > matrix, int cnt)
{
	int num_connected = 0;
	int *isfound = new int[cnt + 1];
	for (int i = 1; i < cnt + 1; i++)
		isfound[i] = 0;

	//以k为根节点不断进行广度优先遍历
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
				//广度优先，如果没有探寻过
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


	//数连通分量
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
	vector<int>::iterator it = answer.begin(); //定义前向迭代器 
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