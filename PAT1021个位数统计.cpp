#include<iostream>
#include<string>
using namespace std;


int main()
{
	string input;
	cin >> input;

	int arr[10] = { 0 };
	int cnt;
	for (int i = 0; i < input.size(); i++)
	{
		cnt = input[i] - '0';
		arr[cnt]++;
	}
	
	for (int i = 0; i < 10; i++)
	{
		if(arr[i])
			cout << i << ":" << arr[i] << endl;
	}
	system("pause");
	return 0;
}