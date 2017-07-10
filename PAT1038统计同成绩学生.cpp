#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<cstdio>
using namespace std;

int main()
{
	int arr[101] = { 0 };
	int N;
	int num;
	cin >> N;
	
	while (N != 0)
	{
		cin >> num;
		arr[num]++;
		N--;
	}

	int i;
	int temp;
	cin >> i;

	while (i)
	{
		cin >> temp;
		cout << arr[temp];
		i--;
		if (i) cout << " ";
	}

	//system("pause");
	return 0;
}