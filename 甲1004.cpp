#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


/*	这题我用朋友圈那题的思路，即集合的思路，每个树节点有parent，childnum和level三个元素，
parent代表它的父节点，如果是根节点则为-1，然后输入完childnum那些数据后。
	每一个在树中出现的节点，向上搜寻，不断调用自己的parent从而召唤父节点，当找到根节点时停止，此时为这一个节点的层数。
然后找到最大层数。总结的时候再找一个数组，将相同层数的子节点为0的数目相加即可 
	注意当M=0，要输出1*/



struct treenode
{
	int parent;
	int childnum;
	int level;
};


bool cmp(treenode&t1, treenode&t2)
{
	return t1.level <= t2.level;
}

int main()
{
	int N, M;
	cin >> N >> M;
	treenode*arr = new treenode[101];
	for (int i = 0; i < 101; i++) {
		arr[i].childnum = 0;
		arr[i].level = 1;
		arr[i].parent = -2;
	}

	for (int i = 0; i < M; i++)
	{
		int id, childnum;
		cin >> id >> childnum;
		arr[id].childnum = childnum;
		if(arr[id].parent==-2)
			arr[id].parent = -1;
		for (int i = 0; i < childnum; i++) {
			int temp;
			cin >> temp;
			arr[temp].parent = id;
		}
	}
	int max = 1;
	for (int i = 0; i <101; i++) {
		if (arr[i].parent != -2)
		{
			int idx, cnt;
			idx = i, cnt = 1;
			while (arr[idx].parent >= 0)
			{
				idx = arr[idx].parent;
				cnt++;
			}
			arr[i].level = cnt;
			if (cnt > max) max = cnt;
		}
	}

	int ans[200] = { 0 };
	for (int i = 0; i < 101; i++)
	{
		if (arr[i].parent != -2 && arr[i].childnum == 0)
		{
			ans[arr[i].level]++;
		}
	}
	int state = 1;
	if (max == 1) cout << 1;
	else {
		for (int i = 1; i <= max; i++)
		{
			if (state)
				cout << ans[i], state = 0;
			else
				cout << " " << ans[i];
		}
	}
	delete[]arr;
	system("pause");
	return 0;
}