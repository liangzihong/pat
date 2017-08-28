#include<iostream>
#include<algorithm>
#include<string>
#include<map>
#include<cstdio>
using namespace std;


struct student
{
	string num;
	int cmark;
	int mmark;
	int emark;
	int amark;
	int rank;
	char type;
};

bool cmpa(student a, student b)
{
	return a.amark > b.amark;
}

bool cmpc(student a, student b)
{
	return a.cmark > b.cmark;
}

bool cmpm(student a, student b)
{
	return a.mmark > b.mmark;
}

bool cmpe(student a, student b)
{
	return a.emark > b.emark;
}

typedef pair<int, char> Pair;


int main()
{
	int N; int M;
	cin >> N >> M;
	student*arr = new student[N+1];
	map<string, Pair> mmap;
	for (int i = 1; i <= N; i++)
	{
		cin >> arr[i].num;
		cin >> arr[i].cmark;
		cin >> arr[i].mmark;
		cin >> arr[i].emark;
		arr[i].amark = (arr[i].cmark + arr[i].emark + arr[i].mmark) / 3;
	}

	sort(&arr[1], &arr[N + 1], cmpa);
	for (int i = 1; i <= N; i++)
	{
		int temprank = i;
		if (i > 1 && arr[i].amark == arr[i - 1].amark)
			temprank = arr[i - 1].rank;

		arr[i].rank = temprank;
		arr[i].type = 'A';
		mmap[arr[i].num].first= arr[i].rank;
		mmap[arr[i].num].second = arr[i].type;
	}

	sort(&arr[1], &arr[N + 1], cmpc);
	for (int i = 1; i <= N; i++)
	{
		int temprank = i;
		int tempi = i;
		while (tempi > 1 && arr[tempi].cmark == arr[tempi - 1].cmark)
		{
			tempi--;
		}
		temprank = tempi;
		if (temprank < arr[i].rank)
		{
			arr[i].rank = temprank;
			arr[i].type = 'C';

			mmap[arr[i].num].first = arr[i].rank;
			mmap[arr[i].num].second = arr[i].type;
		}
	}

	sort(&arr[1], &arr[N + 1], cmpm);
	for (int i = 1; i <= N; i++)
	{

		int temprank = i;
		int tempi = i;
		while (tempi > 1 && arr[tempi].mmark == arr[tempi - 1].mmark)
		{
			tempi--;
		}
		temprank = tempi;
		if (temprank < arr[i].rank)
		{
			arr[i].rank = temprank;
			arr[i].type = 'M';
			mmap[arr[i].num].first = arr[i].rank;
			mmap[arr[i].num].second = arr[i].type;
		}
	}

	sort(&arr[1], &arr[N + 1], cmpe);
	for (int i = 1; i <= N; i++)
	{
		int temprank = i;
		int tempi = i;
		while (tempi > 1 && arr[tempi].emark == arr[tempi - 1].emark)
		{
			tempi--;
		}
		temprank = tempi;
		if (temprank < arr[i].rank)
		{
			arr[i].rank = temprank;
			arr[i].type = 'E';
			mmap[arr[i].num].first = arr[i].rank;
			mmap[arr[i].num].second = arr[i].type;
		}
	}

	for (int i = 0; i < M; i++)
	{
		string temp;
		cin >> temp;
		if (mmap[temp].first > 0 && mmap[temp].first < 2001)
			cout << mmap[temp].first << " " << mmap[temp].second << endl;
		else
			cout << "N/A" << endl;
	}
	system("pause");
	return 0;
}