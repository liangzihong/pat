#include<iostream>
#include<cstdio>
#include<string>
#include<cctype>
using namespace std;

void changeto13(int n)
{
	int shiwei, gewei;
	shiwei = n / 13;
	gewei = n % 13;
	if (shiwei >= 10) 
		cout << char(shiwei + 55);
	else cout << shiwei;
	if (gewei >= 10)
		cout << char(gewei + 55);
	else cout << gewei;
}



int main()
{
	int first, second, third;
	cin >> first >> second >> third;
	cout << "#";
	changeto13(first);
	changeto13(second);
	changeto13(third);
	system("pause");
	return 0;

}