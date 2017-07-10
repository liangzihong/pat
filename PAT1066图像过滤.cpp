#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
	int M;
	int N;
	cin >> M >> N;
	int A;
	int B;
	cin >> A >> B;
	int swap;
	cin >> swap;
	int input;
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			scanf("%d", &input);
			if (input >= A&&input <= B)
			{
				printf("%03d", swap);
				if (j != N - 1) printf(" ");
			}
			else
			{
				printf("%03d", input);
				if (j != N - 1) printf(" ");
			}
		}
		printf("\n");
	}

	//system("pause");
	return 0;
}