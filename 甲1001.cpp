#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
using namespace std;

int main()
{
	int a, b;
	cin >> a >> b;
	int c = a + b;
	if (c < 0) cout << "-";
	c = abs(c);
	string arr;
	int len;
	int state = 1;
	arr = to_string(c);
	len = arr.size();
	if (len % 3 == 1)
	{
		cout << arr[0];
		if (len != 1) cout << ",";
		arr.erase(arr.begin());
	}
	else if (len % 3 == 2)
	{
		cout << arr[0] << arr[1];
		if (len != 2) cout << ",";
		arr.erase(arr.begin(), arr.begin() + 2);
	}
	len = arr.size();
	for (int i = 0; i < len; i++)
	{
		cout << arr[i];
		if ((i + 1) % 3 == 0 && i + 1 != len)
			cout << ",";
	}
	system("pause");
	return 0;
}