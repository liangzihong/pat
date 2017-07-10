#include<iostream>
#include<cmath>
using namespace std;

bool isprime(int n)
{
	if (n == 2) { return true; }
	for (int i = 2; i <= sqrt(n); i++)
	{
		if(n%i==0)
		{
			return false;
		}
	}
	return true;
}


int main()
{
	int max;
	cin >> max;

	int* arr = new int[max];
	int num = 0;
	int cnt=0;

	for (int i = 2; i <= max; i++)
	{
		if (isprime(i))
		{
			arr[cnt++] = i;
		}
	}

	for (int i = 0; i < cnt; i++)
	{
		if (arr[i] + 2 == arr[i + 1])
			num++;
	}


	cout << num;
	system("pause");
	return 0;
}