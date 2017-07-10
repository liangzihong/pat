#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
typedef struct fuck
{
	string name;
	string date;
}people;

bool cmp(people&a, people&b)
{
	if (a.date < b.date) return true;
	else return false;
}

int main()
{
	int N; cin >> N;
	int real = 0;
	string biggest = "2014/09/06";
	string smallest = "1814/09/06";
	people*arr = new people[N];
	for (int i = 0; i < N; i++)
	{
		string tempname; cin >> tempname;
		string tempdate; cin >> tempdate;
		if (tempdate >= smallest
			&&tempdate <= biggest)
		{
			arr[real].name = tempname;
			arr[real].date = tempdate;
			real++;
		}
	}
	if (real== 0)
	{
		cout << real;
	}
	else {
		sort(&arr[0], &arr[real], cmp);
		cout << real << " ";
		cout << arr[0].name << " " << arr[real - 1].name;
	}
	delete[]arr;
	system("pause");
	return 0;
}