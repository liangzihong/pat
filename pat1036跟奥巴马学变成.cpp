#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//»ı÷«Ã‚


void show(char ch)
{
	cout << ch;
}

int main()
{
	int N;
	cin >> N;
	char ch;
	cin >> ch;
	int row;
	row = N / double(2) + 0.5;
	vector<char> arr1(N, ch);
	vector<char> arr2(1,ch);

	arr2.insert(arr2.begin()+1, N - 2, ' ');
	arr2.push_back(ch);

	for_each(arr1.begin(), arr1.end(), show);
	cout << endl;
	for (int i = 0; i < row-2; i++)
	{
		for_each(arr2.begin(), arr2.end(), show);
		cout << endl;
	}
	for_each(arr1.begin(), arr1.end(), show);
	system("pause");
	return 0;
}