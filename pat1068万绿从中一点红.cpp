#include<iostream>
#include<map>
using namespace std;
			

int dir[8][2] = { {-1,-1},{ -1,0 }, {-1,1} ,{0,-1} ,{0,1}, {1,-1} ,{1,0}, {1,1} };
int **arr;
int N, M;

bool judge(int i, int j,int distance)
{

	for (int k = 0; k < 8; k++) 
	{
		if (i + dir[k][0] >= 0 && i + dir[k][0] < N&&j + dir[k][1]>=0 && j + dir[k][1] < M) 
		{
			if (arr[i][j] - arr[i + dir[k][0]][j + dir[k][1]] >= -distance &&
				arr[i][j] - arr[i + dir[k][0]][j + dir[k][1]] <= distance)
				return false;
		}
	}
	return true;
}

int main()
{
	int marki, markj;
	int cnt = 0;

	map<int, int> mapp;
	cin >> M >> N;
	int distance;
	cin >> distance;

	arr = new int*[N];
	for (int i = 0; i < N; i++) {
		arr[i] = new int [M];
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> arr[i][j];
			mapp[arr[i][j]]++;
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (mapp[arr[i][j]] == 1 && judge(i, j,distance) == true)
			{
				cnt++;
				marki = i, markj = j;
			};
		}
	}

	if (cnt > 1)
		cout << "Not Unique";
	else if (cnt == 0)
		cout << "Not Exist";
	else
		cout << "(" << markj + 1 << ", " << marki + 1 << "): " << arr[marki][markj] << endl;
	system("pause");
	return 0;
}


