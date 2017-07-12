#include<iostream>
#include<map>
#include<string>
#include<cctype>
using namespace std;


int main()
{
	char ch;
	map<char, int> mapp;
	string need;
	int cnt = 0;   //缺几个
	int all = 0;   //多几个
	while ((ch = cin.get()) != '\n')
	{
		if (isalnum(ch))
		{
			mapp[ch]++;
			all++;
		}
	}
	getline(cin, need);
	for (int i = 0; i < need.size(); i++)
	{
		if (isalnum(need[i]))
		{
			if (mapp[need[i]] != 0)     //有
			{
				mapp[need[i]]--;
				all--;
			}
			else {                      //没有
				cnt++;
			}
		}
	}

	if (cnt == 0)
		cout << "Yes " << all;
	else
		cout << "No " << cnt;
	system("pause");
	return 0;
}