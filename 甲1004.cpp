#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


/*	������������Ȧ�����˼·�������ϵ�˼·��ÿ�����ڵ���parent��childnum��level����Ԫ�أ�
parent�������ĸ��ڵ㣬����Ǹ��ڵ���Ϊ-1��Ȼ��������childnum��Щ���ݺ�
	ÿһ�������г��ֵĽڵ㣬������Ѱ�����ϵ����Լ���parent�Ӷ��ٻ����ڵ㣬���ҵ����ڵ�ʱֹͣ����ʱΪ��һ���ڵ�Ĳ�����
Ȼ���ҵ����������ܽ��ʱ������һ�����飬����ͬ�������ӽڵ�Ϊ0����Ŀ��Ӽ��� 
	ע�⵱M=0��Ҫ���1*/



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