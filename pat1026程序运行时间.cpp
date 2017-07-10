#include<iostream>
#include<iomanip>
#include<cstdio>

//ÈõÖÇÌâ

using namespace std;
const int per = 100;
int main()
{
	int a;
	int b;
	cin >> a >> b;
	cout.precision(2);
	cout << setw(2) << setfill('0');
	int hour = ((b-a)/per) / 3600;
	printf("%02d:", hour);
	int min;
	min = (((b - a) / per) - hour * 3600)/60;
	printf("%02d:", min);
	int second = double(((double(b - a) / per) - double(hour * 3600) - min * 60)+0.5);
	printf("%02d", second); 
	system("pause");
	return 0;
}