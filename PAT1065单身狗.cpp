#include<iostream>
#include<vector>
#include<cstdio>
#include<algorithm>
using namespace std;


//�����⣬������Ͳ�˵��

class fuck
{
public:
	int partner;
	int value;
	fuck()
	{
		partner = -1;
		value = 0;
	}
};


int main()
{
	int N;
	cin >> N;
	fuck*arr = new fuck[100000];
	
	int my, partner;
	for (int i = 0; i < N; i++)
	{
		cin >> my >> partner;
		arr[my].partner = partner;
		arr[partner].partner = my;
	}

	int cnt;  //������������
	cin >> cnt;
	int temp;
	for (int i = 0; i < cnt; i++)
	{
		cin >> temp;
		arr[temp].value = 1;
	}

	vector<int> answer; //Ҫ����Ĵ�
	int single = 0;  //��������Ŀ
	for (int i = 0; i < 100000; i++)
	{
		if (arr[i].value == 1 && arr[i].partner == -1)
		{
			single++;
			answer.push_back(i);
		}
		else if (arr[i].value == 1 && arr[i].partner != -1
			&& arr[arr[i].partner].value == 0)
		{
			single++; answer.push_back(i);
		}
	}
	sort(answer.begin(), answer.end());
	cout << single << endl;
	for (int i = 0, idx = 0; i < answer.size(); i++)
	{
		printf("%05d", answer[i]);
		idx++;
		if (idx != single) cout << " ";
	}
	delete[]arr;
	//system("pause");
	return 0;
}
