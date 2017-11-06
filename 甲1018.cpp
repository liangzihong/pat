#include<iostream>
#include<string>
#include<cmath>
#include<stack>
#include<vector>
using namespace std;


//����ԭ����Ŀ��˼�ǻس̵�ʱ���ǲ��ܹ�����������һ��ʼ��˼·����
//������ʵҪ���������·�����������Ȼ����ÿһ��������һ�Σ���˭��Ҫ������

//������dijkstra��������μ�¼������·��
//�𰸾�����dfs��������Ȳ��ϱ�����ֱ��������Ϊ0��ʱ������жϣ����඼ѭ����dfsһ���㣬Ȼ����pop�����еݹ�

//���Լ�¼�������·��  ��  dijkstra+dfs


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
	//��̾��������ʼ��
	int *distance = new int[cntvertex + 1];
	distance[0] = 0;
	isfound[0] = 0;
	for (int i = 1; i < cntvertex + 1; i++)
		distance[i] = 65534, isfound[i] = 0;


	//��Ϊ����һ�����ж���·����������Ҫ��ÿ��·��������
	vector<int> *points = new vector<int>[cntvertex + 1];
	points[0].push_back(-1);

	//Ҫ��cntvertex+1�������һ�Σ�����Ҫ��cntvertex+1��ѭ��
	for (int i = 0; i < cntvertex + 1; i++)
	{
		int k = findmin(isfound, distance, cntvertex);
		isfound[k] = 1;
		if (k == target) break;

		for (int j = 1; j < cntvertex + 1; j++)
		{
			if (isfound[j] == 0 && j != k)
			{
				//��������С����ôֱ�ӱ��
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

	//��Ϊcntvertexû�а���0������Ҫ����0������Ҫ��1��
	int **matrix = new int*[cntvertex + 1];
	Station *stations = new Station[cntvertex + 1];

	for (int i = 0; i < cntvertex + 1; i++)
		matrix[i] = new int [cntvertex + 1];

	//factΪʵ��������fixΪ�����������������������֤���̨�����������֤��Ҫ�Ἰ̨��
	//���Ը������⣬���ȥԽ��Խ�ã������������0��Խ��Խ�ã��������0��Խ��Խ�ã�����0������0��
	stations[0].fix = 0;
	for (int i = 1; i < cntvertex + 1; i++) {
		cin >> stations[i].fact;
		stations[i].fix =stations[i].fact- maxbike/2  ;
	}

	//�����ʼ��Ϊ65534
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




















