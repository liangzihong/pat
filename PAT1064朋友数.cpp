#include<iostream>
#include<set>
#include<algorithm>
using namespace std;

//»ı÷«Ã‚

void show(int a)
{
	cout << a<<" ";
}
int main()
{
	int N;
	cin >> N;
	set<int> arr;
	char ch;
	cin.get();
	for (int i = 0; i < N; i++)
	{
		int num = 0;
		while ((ch = cin.get())!= ' ' && ch != '\n')
		{
			num +=ch - '0';
		}
		arr.insert(num);
	}
	cout << arr.size() << endl;
	set<int>::iterator it = arr.end();

	for_each(arr.begin(), --it, show);
	cout << *it;

	//system("pause");
	return 0;
}