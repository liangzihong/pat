#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class road
{
public:
	int distance;
	int cost;
	road() {
		distance = 65535;
		cost = 0;
	}
};



int main()
{
	int cntvertex;
	int cntedge;
	int start;
	int end;
	cin >> cntvertex >> cntedge >> start >> end;

	road **matrix = new road*[cntvertex];
	for (int i = 0; i < cntvertex; i++) {
		matrix[i] = new road[cntvertex];
		matrix[i][i].distance = 0;
	}

	for (int i = 0; i < cntedge; i++) {
		int a, b;
		cin >> a >> b;
		int dist, cost;
		cin >> dist >> cost;
		matrix[a][b].distance = matrix[b][a].distance=dist;
		matrix[a][b].cost = matrix[b][a].cost=cost;
	}


	int shortestlen = 65535;

	int *parent = new int[cntvertex];
	parent[start] = -1;
	int *isfound = new int[cntvertex];
	int*distance = new int[cntvertex];
	int*costs = new int[cntvertex];
	fill(costs, costs + cntvertex, 65535);
	fill(parent, parent + cntvertex, -1);
	fill(distance, distance + cntvertex, 65535);
	fill(isfound, isfound + cntvertex, 0);

	distance[start] = 0;
	costs[start] = matrix[start][start].cost;
	
	for (int i = 0; i < cntvertex; i++) 
		distance[i] = matrix[start][i].distance;

	for (int i = 0; i < cntvertex; i++)
	{
		int min = 65535;
		int k = -1;
		for (int j = 0; j < cntvertex; j++)
		{
			if (isfound[j] == 0 && distance[j] < min)
				k = j, min = distance[j];
		}

		isfound[k] = 1;

		if (k == end) break;

		for (int j = 0; j < cntvertex; j++)
		{
			int tempdist = matrix[k][j].distance;
			int tempcost = matrix[k][j].cost;
			
			if (isfound[j] == 0 && tempdist + distance[k] < distance[j]) {
				parent[j] = k;
				distance[j] = tempdist + distance[k];
				costs[j] = costs[k] + tempcost;
			}

			else if (isfound[j] == 0 && tempdist + distance[k] == distance[j] && tempcost + costs[k] < costs[j]) {
				parent[j] = k;
				distance[j] = tempdist + distance[k];
				costs[j] = costs[k] + tempcost;
			} 
		}
	}

	vector<int>answer;
	for (int i = end; i != -1;) {
		answer.push_back(i);
		i = parent[i];
	}

	for (int i = answer.size()-1; i >=0; i--)
		cout << answer[i]<< " ";

	cout << distance[end] << " " << costs[end];

	system("pause");
	return 0;
} 