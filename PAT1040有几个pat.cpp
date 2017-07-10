#include<iostream>
#include<string>
using namespace std;

int main()
{
	int temp;
	int sum=0;
	int countt=0;
	int countp=0;

	string arr;
	cin >> arr;

	for (int i = 0; i<arr.size(); i++)
	{
		if (arr[i] == 'T')
			countt++;
	}

	for (int i = 0; i<arr.size(); i++)
	{
		if (arr[i] == 'P')
			countp++;
		else if (arr[i] == 'A')
		{
			temp = ((countp% 1000000007 )*(countt% 1000000007))% 1000000007;
			sum = (sum+temp)% 1000000007;
		}
		else
		{
			countt--;
		}
			
	}
	cout << sum;
	system("pause");
	return 0;
}