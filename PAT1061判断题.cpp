#include<iostream>
#include<valarray>
#include<vector>
using namespace std;
//弱智题
int main()
{
	int stunum;
	int tinum;
	cin >> stunum >> tinum;

	vector<int> answer(tinum);
	vector<int> mark(tinum);
	for (int i = 0; i < tinum; i++)
	{
		cin>> mark[i];
	}
	for (int i = 0; i < tinum; i++)
	{
		cin >> answer[i];
	}

	valarray<int> val(tinum);       //答案正误放的地方

	for (int i = 0; i < stunum; i++)
	{
		int ans;
		int res = 0;
		for (int j = 0; j < tinum; j++)
		{
			cin >> ans;
			if (ans == answer[j])
			{
				res+= mark[j];
			}
		}
		cout << res << endl;
	}

	//system("pause");
	return 0;
}