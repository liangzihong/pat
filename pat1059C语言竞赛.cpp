#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;

struct fuck
{
	int rank;
	int num;
};


bool judge(int aaa)
{
	for (int i = 2; i <= sqrt(aaa); i++)
	{
		if (aaa%i == 0)
			return false;
	}
	return true;
}






int main()
{
	int N;
	int mark;
	scanf("%d",&N);
	int record[100000] = { 0 };
	fuck*arr = new fuck [100000];
	for (int i = 0; i < N; i++) {
		scanf("%d", &mark);
		arr[mark].num = mark;
		arr[mark].rank = i + 1;
		record[mark]=1;
	}
	int M;
	cin >> M;
	for (int i = 0; i < M; i++) {
		scanf("%d", &mark);
		printf("%04d: ", mark);
		if (record[mark] == 0)
			cout << "Are you kidding?\n";
		else if (record[mark] == -1)
			cout << "Checked\n";
		else {
			if (arr[mark].rank == 1) {
				cout << "Mystery Award\n";
				record[mark] = -1;
			}
			else if (judge(arr[mark].rank)) {
				cout << "Minion\n";
				record[mark] = -1;
			}
			else
			{
				cout << "Chocolate\n";
				record[mark] = -1;
			}
		}
	}
	delete[]arr;
	system("pause");
	return 0;
	
}