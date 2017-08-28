#include<iostream>
#include<vector>
#include<algorithm>
#include<deque>
#include<cstdio>

using namespace std;


typedef int Matrix[1001][1001];

struct Edgetype
{
	int end;
	Edgetype *next;
};

struct Vertextype
{
	int start;
	Edgetype*first;
};


struct Graph
{
	int cntvertex;
	int cntedge;
	Vertextype *adj;
	int cntshow;
	Matrix matrix;
};


typedef Graph* MGraph;

MGraph create(MGraph mg)
{
	if (mg != NULL)
		return mg;
	mg = new Graph;
		
	scanf("%d %d %d",&mg->cntvertex,&mg->cntedge,&mg->cntshow);
	mg->adj = new Vertextype[mg->cntvertex + 1];

	/*for (int i = 1; i <= mg->cntvertex; i++)
	{
		mg->adj[i].start = i;
		mg->adj[i].first = NULL;
	}*/

	for (int i = 0; i < mg->cntedge; i++)
	{
		int st;
		int ed;
		scanf("%d %d",&st,&ed);
		mg->matrix[st][ed] = 1;
		mg->matrix[ed][st] = 1;

		/*Edgetype *temp1 = new Edgetype;
		temp1->end = ed;
		temp1->next = mg->adj[st].first;
		mg->adj[st].first = temp1;

		Edgetype *temp2 = new Edgetype;
		temp2->end = st;
		temp2->next = mg->adj[ed].first;
		mg->adj[ed].first = temp2;*/
	}
	return mg;
}


void dfs(MGraph mg, int n, int visited[])
{
	visited[n] = 1;
	for (int i = 1; i < 1001; i++)
	{
		if (mg->matrix[n][i] == 1 && visited[i] == 0)
			dfs(mg, i, visited);
	}
}

//数连通分量的函数
int count(MGraph mg, int n)
{
	int cnt = 0;
	int judge[1200] = { 0 };
	judge[n] = 1;
	for(int idx=1;idx<=mg->cntvertex;idx++)
	{
		int k = idx;
		if (judge[k] == 1)
			continue;
		

		cnt++;
		/*deque<int> ARR;
		ARR.push_back(k);
		while (ARR.size() != 0)
		{
			int j = ARR.front();
			ARR.pop_front();
			judge[j] = 1;

			for (int i = 1; i <= 1000; i++)
			{
				if (mg->matrix[j][i] == 1&&judge[i]==0)
					ARR.push_back(i);
			}

		}*/
		dfs(mg, k, judge);
	}
	return cnt;
}




int main()
{
	MGraph mg = NULL;
	mg = create(mg);
	int *show = new int[mg->cntshow];
	for (int i = 0; i < mg->cntshow; i++)
	{
		scanf("%d", &show[i]);
		int res = count(mg, show[i]);
		printf("%d\n", res - 1);
	}

	system("pause");
	return 0;


}