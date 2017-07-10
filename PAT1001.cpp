#include<iostream>
using namespace std;
int main()
{
	int a; int cnt=0;
	cin >> a;
	while (a != 1)
	{
		if (a % 2)
		{
			a = (a * 3 + 1) / 2;
		}
		else
		{
			a /= 2;
		}
		cnt++;
	}
	cout << cnt << endl;
	system("pause");
	return 0;
}