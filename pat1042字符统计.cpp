#include<iostream>
#include<cctype>
using namespace std;

int main()
{
	int arr[26] = { 0 };
	char ch;
	int a;
	int i;
	int max;
	ch = cin.get();
	while (ch != '\n')
	{
		if (isalpha(ch))
		{
			ch = isupper(ch) ? (ch + 32) : ch;
			a = ch - 97;
			arr[a]++;
		}
		ch = cin.get();
	}
	max = arr[0]; int k=0;
	for (i = 0; i < 26; i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
			k = i;
		}
	}
	i = k;
	ch = char(i + 97);
	cout << ch<< " " << arr[i] << endl;
	system("pause");
	return 0;
}