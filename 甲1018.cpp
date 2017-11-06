#include<iostream>
#include<string>
#include<cmath>
#include<stack>
#include<vector>
using namespace std;


//错误：原来题目意思是回程的时候是不能够调整，所以一开始的思路错误
//所以其实要把所有最短路径都搞出来，然后在每一个都遍历一次，看谁需要的最少

//所以在dijkstra基础上如何记录多个最短路径
//答案就是用dfs，深度优先不断遍历，直到遍历点为0的时候进入判断，其余都循环，dfs一个点，然后再pop，进行递归

//所以记录多条最短路径  用  dijkstra+dfs


struct Station
{
	int fact;
	int fix;
	int minbring;
};


vector<int> temppath;
vector<int> path;
int minneed=65534;
int minbring=65534;

void dfs(vector<int> arr[], Station stations[],int cntvertex,int idx)
{
	temppath.push_back(idx);
	if (idx == 0)
	{
		int collected = 0;
		int need = 0;
		for (int i = temppath.size() - 1; i >= 0; i--)
		{
			int a = temppath[i];
			int fix = stations[a].fix;
			if (fix <= 0)
			{
				if (collected == 0)
					need += abs(fix);
				else if (collected > -fix)
					collected += fix;
				else if (collected < -fix)
					need = need + (-fix - collected),collected = 0 ;
			}
			else collected += fix;
		}

		if ((need < minneed)||(need == minneed&&collected<minbring))
			path = temppath, minneed = need, minbring = collected;
	}

	else
	{
		for (int i = 0; i < arr[idx].size(); i++)
		{
			dfs(arr, stations,cntvertex, arr[idx][i]);
			temppath.pop_back();
		}
	}

}

int findmin(int isfound[], int distance[], int cntvertex)
{
	int min = 65534;
	int target = 0;
	for (int i = 0; i < cntvertex + 1; i++)
	{
		if (isfound[i] == 0 && distance[i] < min)
			min = distance[i], target = i;
	}
	return target;
}


void dijkstra(int* matrix[], Station stations[], int cntvertex, int target)
{
	int *isfound = new int[cntvertex + 1];
	//最短距离数组初始化
	int *distance = new int[cntvertex + 1];
	distance[0] = 0;
	isfound[0] = 0;
	for (int i = 1; i < cntvertex + 1; i++)
		distance[i] = 65534, isfound[i] = 0;


	//因为可能一个点有多条路径，所以需要把每条路径都搞来
	vector<int> *points = new vector<int>[cntvertex + 1];
	points[0].push_back(-1);

	//要把cntvertex+1个点遍历一次，所以要做cntvertex+1次循环
	for (int i = 0; i < cntvertex + 1; i++)
	{
		int k = findmin(isfound, distance, cntvertex);
		isfound[k] = 1;
		if (k == target) break;

		for (int j = 1; j < cntvertex + 1; j++)
		{
			if (isfound[j] == 0 && j != k)
			{
				//如果距离更小，那么直接变更
				if (distance[k] + matrix[k][j] < distance[j]) {
					points[j].clear();
					points[j].push_back(k);
					distance[j] = distance[k] + matrix[k][j];
				}
				else if (distance[k] + matrix[k][j] == distance[j])
					points[j].push_back(k);
			}
		}
	}

	dfs(points, stations,cntvertex, target);

	cout << minneed << " ";
	for (int j = path.size() - 1; j >= 0; j--)
	{
		cout << path[j];
		if (j != 0)
			cout<< "->";
	}
	cout << " " << minbring;
}



int main()
{
	int maxbike;
	cin >> maxbike;
	int cntvertex, cntedge;
	int problem;
	cin >> cntvertex >>problem>> cntedge;

	//因为cntvertex没有包括0，所以要加上0，所以要加1；
	int **matrix = new int*[cntvertex + 1];
	Station *stations = new Station[cntvertex + 1];

	for (int i = 0; i < cntvertex + 1; i++)
		matrix[i] = new int [cntvertex + 1];

	//fact为实际数量，fix为离完美的数量，如果负数，证明差几台，如果整数，证明要搬几台。
	//所以根据题意，搬过去越少越好，所以如果少于0，越大越好，如果大于0，越少越好，大于0比少于0好
	stations[0].fix = 0;
	for (int i = 1; i < cntvertex + 1; i++) {
		cin >> stations[i].fact;
		stations[i].fix =stations[i].fact- maxbike/2  ;
	}

	//距离初始化为65534
	for (int i = 0; i < cntvertex + 1; i++)
		for (int j = 0; j < cntvertex + 1; j++)
			matrix[i][j] = 65534;

	for (int i = 1; i <= cntedge; i++)
	{
		int a, b,distance;
		cin >> a >> b>>distance;
		matrix[a][b] = matrix[b][a] = distance;
		matrix[a][a] = matrix[b][b] = 0;
	}

	dijkstra(matrix, stations, cntvertex,problem);

	system("pause");
}




















