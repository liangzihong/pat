#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main()
{
	long a;
	long b;
	cin >> a >> b;
	long result;
	result = a + b;
	int d;
	cin >> d;
	vector<int> arr;
	if (result == 0)
	{
		cout << 0;
	}
	else {
		while (result != 0)
		{
			arr.push_back(result%d);
			result /= d;
		}
		int state = 1;
		for (int i = arr.size() - 1; i >= 0; i--)
		{
			if (state&&arr[i] == 0) {
				state = 0;
			}
			else
			{
				cout << arr[i];
				state = 0;
			}
		}
	}
	system("pause");
	return 0;
}

