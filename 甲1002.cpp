#include<iostream>
using namespace std;

int main()
{
	double arr1[1001];
	double arr2[1001];
	for (int i = 0; i < 1001; i++) { arr1[i] = arr2[i] = 0; }
	int T1; int T2;
	int temp;
	double aaa;
	cin >> T1;
	for (int i = 0; i < T1; i++) {
		cin >> temp;
		cin >> aaa;
		arr1[temp] = aaa;
	}
	cin >> T2;
	for (int i = 0; i < T2; i++) {
		cin >> temp;
		cin >> aaa;
		arr2[temp] = aaa;
	}

	double arr3[1001] = { 0 };
	int cnt = 0;
	for (int i = 1000; i >= 0; i--)
	{
		arr3[i] = arr1[i] + arr2[i];
		if (arr3[i] != 0)
			cnt++;
	}
	
	cout << fixed;
	cout.precision(1);
	if (cnt == 0)
		cout << 0;
	else
	{
		cout << cnt << " ";

		for (int i = 1000; i >= 0; i--)
		{
			if (arr3[i] != 0)
			{
				cout << i << " " << arr3[i];
				cnt--;
				if (cnt != 0) cout << " ";
			}
		}
	}
	system("pause");
	return 0;

}