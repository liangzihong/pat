#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdio>
using namespace std;


int main()
{
	vector<long> answer;
	int all = 0;
	for (int i = 0; i < 2; i++)
	{
		int cnt;
		scanf("%d",&cnt);
		all += cnt;
		for (int i = 0; i < cnt; i++) {
			long temp;
			scanf("%ld", &temp);
			answer.push_back(temp);
		}
	}
	sort(answer.begin(), answer.end());
	if(all%2==0)
		printf("%ld", answer[all / 2-1]);
	else
		printf("%ld", answer[all / 2]);
	system("pause");
	return 0;
}