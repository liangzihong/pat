#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

//ÈõÖÇÌâ

typedef struct fuck
{
	int teamnum;
	int grade;
}team;

bool cmp(team&a, team&b)
{
	if (a.grade > b.grade) return true;
	return false;
}

int main()
{
	int N;
	cin >> N;

	team arr[1001];
	for (int i = 0; i < 1001; i++) {
		arr[i].teamnum = i;
		arr[i].grade = 0;
	}

	for (int i = 0; i < N; i++) {
		int num; int temp; int mark;
		scanf("%d-%d %d", &num, &temp, &mark);
		arr[num].grade += mark;
	}

	sort(arr, arr + 1001, cmp);
	cout << arr[0].teamnum << " " << arr[0].grade;
	system("pause");
	return 0;
}