#include<iostream>
#include<string>
using namespace std;

int main()
{
	string input;
	cin >> input;
	int sum=0;
	for (int i = 0; i < input.size(); i++) {
		int temp = input[i] - '0';
		sum += temp;
	}
	string ans = to_string(sum);
	for (int i = 0; i < ans.size(); i++)
	{
		switch (ans[i])
		{
		case '0':cout << "zero"; break;
		case '1':cout << "one"; break;
		case '2':cout << "two"; break;
		case '3':cout << "three"; break;
		case '4':cout << "four"; break;
		case '5':cout << "five"; break;
		case '6':cout << "six"; break;
		case '7':cout << "seven"; break;
		case '8':cout << "eight"; break;
		case '9':cout << "nine"; break;
		}
		if (i + 1 != ans.size())
			cout << " ";
	}
	system("pause");
	return 0;

}