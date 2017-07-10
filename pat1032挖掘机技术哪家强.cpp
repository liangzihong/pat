#include<iostream>
#include<algorithm>
using namespace std;

//ÈõÖÇÌâ
typedef struct fuck
{
	int n;
	int mark;
}school;

bool cmp(school&a, school&b)
{
	if (a.mark > b.mark) return true;
	return false;
}


int main()
{
	int N; cin >> N;
	school arr[100001];
	for (int i = 0; i < 100001; i++)
	{
		arr[i].n = i; arr[i].mark = 0;
	}
	int num;
	int grade;
	for (int i = 0; i < N; i++) {
		cin >> num;
		cin >> grade;
		arr[num].mark += grade;
	}
	sort(arr, arr + 100001, cmp);
	cout << arr[0].n << " " << arr[0].mark;
	system("pause");
	return 0;
}