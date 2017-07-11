#include<iostream>
#include<map>
#include<string>
using namespace std;


//用map可以你mapp【】一个不存在的，他就会自动帮你添加，并初始化值为0，利用这个可以用做计算重复之类的


int main()
{
	int idx = 0;
	int M, N, S;
	cin >> M >> N >> S;
	string *arr = new string[M+1];
	for (int i = 1; i <= M; i++) {
		cin >> arr[i];
	}
	map<string, int> mapp;
	int cnt = S;
	for (; cnt <= M; cnt+=N)
	{
		if (mapp[arr[cnt]] == 0) {
			idx++;
			cout << arr[cnt] << endl;
		}
		else
		{
			cnt = cnt - N + 1;
			continue;
		}
		mapp[arr[cnt]]++;
	}
	if (idx == 0)
	{
		cout << "Keep going...";
	}

	system("pause");
	return 0;
}
