#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int isprime(int num)
{
	if (num <= 1)return 0;
	for (int i = 2; i <= sqrt(num); i++)
	{
		if (num%i == 0)
			return 0;
	}
	return 1;
}

int reverse(int num,int radix)
{
	vector<int> first;
	
	int a;
	do
	{
		a = num / radix;
		first.push_back(num%radix);
		num = a;
	} while (a != 0);

	int length = first.size();
	int result = 0;
	int newradix = 1;
	for (int i = length - 1; i >= 0; i--)
	{
		result += newradix*first[i];
		newradix = newradix*radix;
	}
	return result;
}


int main()
{
	int a, b;
	cin >> a;
	while (a >= 0)
	{
		cin >> b;
		if (isprime(a) == 1 && isprime(reverse(a, b)) == 1)
			cout << "Yes\n";
		else cout << "No\n";
		cin >> a;
	}
	system("pause");
	return 0;
}