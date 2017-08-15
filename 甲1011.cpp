#include<iostream>
#include<vector>
#include<cstdio>
#include<iomanip>
using namespace std;


int main()
{
	vector<char> arr;
	double sum=1;
	for (int i = 0; i < 3; i++)
	{
		double win, tie, lose;
		cin >> win >> tie >> lose;
		double max;
		if (win >= tie&&win >= lose) max = win, arr.push_back('W');
		else if (tie >= win&&tie >= lose) max = tie, arr.push_back('T');
		else if (lose >= win&&lose >= tie) max = lose, arr.push_back('L');
		sum *= max;
	}
	for (int i = 0; i < 3; i++)
		cout << arr[i] << " ";
	double res = (sum*0.65 - 1) * 2;
	cout << fixed;
	cout << setprecision(2);
	cout << res;
	system("pause");
	return 0;
}