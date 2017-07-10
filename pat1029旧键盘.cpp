#include<iostream>
#include<string>
#include<algorithm>
#include<cctype>
using namespace std;

//弱智题

int main()
{
	string good;
	string bad;
	cin >> good;
	cin >> bad;
	string check = "";
	char temp;
	for (int i = 0; i < good.size(); i++)
	{
		temp = good[i];
		if (bad.find(temp) == string::npos)  //在bad中找不到
		{
			if (check.find(temp) == string::npos)  //在check中也找不到
			{
				check += temp;
				if (isalpha(temp))   //如果是字母则要变大写
				{
					temp = tolower(temp);        //如果是大写字母要变小写
					check += temp;
					temp = toupper(temp);         //然后又变回大写
					check += temp;
				}
				cout << temp;
			}
		}
	}
	system("pause");
	return 0;
}