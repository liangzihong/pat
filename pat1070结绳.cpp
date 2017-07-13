#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int N;
	cin >> N;
	int *arr = new int[N];
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	sort(arr + 0, arr + N);
	for (int i = 0; i < N-1; i++)
	{
		arr[i + 1] = (arr[i] + arr[i + 1]) / 2;
	}
	cout << arr[N - 1];
	system("pause");
	return 0;
}