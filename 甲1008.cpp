#include<iostream>
#include<cmath>
using namespace std;

int main()
{
	int T;
	cin >> T;
	int*arr = new int [T + 1];
	arr[0] = 0;
	for (int i = 1; i < T + 1; i++)
	{
		cin >> arr[i];
	}
	int sum = 0;
	int temp = 0;
	for (int i = 1; i < T + 1; i++) {
		if (arr[i] - arr[i - 1] < 0)
			temp = 4;
		else if (arr[i] - arr[i - 1] > 0)
			temp = 6;
		else temp = 0;
		sum = sum + temp*abs(arr[i] - arr[i - 1])+5;
	}
	cout << sum;
	system("pause");
	return 0;
}