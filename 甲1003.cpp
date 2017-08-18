#include<iostream>
#include<vector>
#include<deque>
#include<fstream>
#include<algorithm>
using namespace std;
#define infinity 65535


int shortest;
int maximum;
int idx;


typedef int Vertextype;
typedef int Weight;
typedef Weight Distance;
typedef Distance Matrix[1000][1000];

struct edgenode
{
	Vertextype end;
	Distance distance;
	edgenode*next;
};

struct Vertexnode
{
	Vertextype myself;
	edgenode *first;
};


struct wayname
{
	int me;
	vector<int> way;
};



struct Graph
{
	int cntvertex;
	int cntedge;
	Matrix matrix;
	Vertexnode *adj;
	Vertextype sp;
	Vertextype ep;
	int *pointweight;
};

typedef Graph* MGraph;

MGraph create(MGraph mg)
{
	if (mg == NULL)
		mg = new Graph;
	else return mg;
	ifstream cin("1.txt", ios::in);
	cin >> mg->cntvertex;
	cin >> mg->cntedge;
	cin >> mg->sp;
	cin >> mg->ep;

	mg->pointweight = new int[mg->cntvertex];
	for (int i = 0; i < mg->cntvertex; i++)
	{
		cin >> mg->pointweight[i];
	}
	mg->adj = new Vertexnode [mg->cntvertex];
	for (int i = 0; i < mg->cntvertex; i++)
	{
		for (int j = 0; j < mg->cntvertex; j++)
		{
			mg->matrix[i][j] = infinity;
		}
		mg->adj[i].first =NULL;
	}

	for (int i = 0; i < mg->cntedge; i++)
	{
		int a, b; Distance temp;
		cin >> a >> b >> temp;
		mg->matrix[a][b] = temp;
		mg->matrix[b][a] = temp;

		edgenode* newedgenode1 = new edgenode;
		newedgenode1->end = b;
		newedgenode1->distance = temp;
		newedgenode1->next= mg->adj[a].first;
		mg->adj[a].first = newedgenode1;

		edgenode* newedgenode2 = new edgenode;
		newedgenode2->end = a;
		newedgenode2->distance = temp;
		newedgenode2->next= mg->adj[b].first;
		mg->adj[b].first = newedgenode2;
	}
	return mg;
}

wayname arr[502];
deque<int> ans;

void easydfs(int n)
{
	ans.push_back(n);
	for (int i = 0; i < arr[n].way.size(); i++)
	{
		easydfs(arr[n].way[i]);
	}
	if(arr[n].way.size()==0)
	{
		for (int i = ans.size() - 1; i >= 0; i--) 
			cout << ans[i] << " ";
		cout << endl;
	}
	ans.pop_back();
}

void dijkstra(MGraph mg, int parent[])
{
	int visited[502] = { 0 };
	int fromsp[502] = { 0 };
	int resurenum[502] = { 0 };
	int waynum[502] = { 0 };                     //最短路径数目初始化
	
	int sp = mg->sp;
	int ep = mg->ep;

	for (int i = 0; i < mg->cntvertex; i++)
	{
		fromsp[i] = mg->matrix[sp][i];			 //最短距离初始化
		resurenum[i] = mg->pointweight[i];       //救援队伍初始化
		arr[i].me = i;
	}
	fromsp[sp] = 0;
	//visited[sp] = 1;
	waynum[sp] = 1;

	for (int i = 0; i < mg->cntvertex; i++)
	{
		int min = infinity;
		int k = sp;
		for (int i = 0; i < mg->cntvertex; i++) {
			if (fromsp[i] < min&&visited[i]==0) {
				min = fromsp[i];
				k = i;
			}
		}
		//if (k == sp) return;
		visited[k] = 1;
		edgenode*edge=mg->adj[k].first;
		for (; edge; edge = edge->next)
		{
			if (visited[edge->end] == 0 && fromsp[k] + edge->distance < fromsp[edge->end])  //绕点有最短路径
			{
				fromsp[edge->end] = fromsp[k] + edge->distance;
				waynum[edge->end] = waynum[k];
				resurenum[edge->end] += resurenum[k];
				arr[edge->end].way.erase(arr[edge->end].way.begin(), arr[edge->end].way.end());
				arr[edge->end].way.push_back(k);
			}
			else if (visited[edge->end] == 0 && fromsp[k] + edge->distance == fromsp[edge->end])  //绕点路径与原先的一样
			{
				waynum[edge->end] += waynum[k];
				resurenum[edge->end]=max(mg->pointweight[edge->end]+resurenum[k],resurenum[edge->end]);
				arr[edge->end].way.push_back(k);
			}
		}
	}
	cout << waynum[ep] << " " << resurenum[ep];
	cout << endl;

	easydfs(ep);
}



int main()
{
	MGraph mg = NULL;
	mg = create(mg);
	int parent[502];
	dijkstra(mg, parent);
	system("pause");
	return 0;
}