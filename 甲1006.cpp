#include<iostream>
#include<cstdio>
#include<string>
using namespace std;

struct people
{
	string name;
	string in;
	string out;
};


int main()
{
	int T;
	cin >> T;
	string early="24:00:00";
	string late="00:00:00";
	string earlyman;
	string lateman;
	people *arr = new people[T];
	for (int i = 0; i < T; i++)
	{
		cin >> arr[i].name;
		cin >> arr[i].in;
		cin >> arr[i].out;
		if (arr[i].in <= early) {
			early = arr[i].in;
			earlyman = arr[i].name;
		}
		if (arr[i].out >= late)
		{
			late = arr[i].out;
			lateman = arr[i].name;
		}
	}
	cout << earlyman << " " << lateman;
	system("pause");
	return 0;
}