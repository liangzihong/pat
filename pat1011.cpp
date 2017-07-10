#include<iostream>
using namespace std;
int main()
{
	long int a;
	long int b;
	long int c;
	int N;
	int cnt = 1;
	cin >> N;

	while (cnt <= N)
	{
		cin >> a;
		cin >> b;
		cin >> c;
		if (a + b > c)
		{
			cout << "Case #" << cnt << ": " << "true" << endl;
		}
		else {
			cout << "Case #" << cnt << ": " << "false" << endl;
		}
		cnt++;
	}
	//system("pause");
	return 0;
}