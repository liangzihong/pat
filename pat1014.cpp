#include<iostream>
#include<string>
#include<cctype>
#include<cstdio>
using namespace std;

int main()
{
	int state1 = 1;
	string one, two, three, four;
	cin >> one >> two >> three >> four;
	for (int i = 0; i < one.size(); i++)
	{
		if (one[i] == two[i] && one[i]<='G'&&one[i]>='A'&&state1)
		{
			state1 = 0;
			switch (one[i])
			{
			case'A':cout << "MON "; break;
			case'B':cout << "TUE "; break;
			case'C':cout << "WED "; break;
			case'D':cout << "THU "; break;
			case'E':cout << "FRI "; break;
			case'F':cout << "SAT "; break;
			case'G':cout << "SUN "; break;
			}
		}
		else if (state1 == 0 && one[i] == two[i] && (one[i] >= 'A'&&one[i]<='N' || isdigit(one[i])))
		{
			if (isdigit(one[i]))
			{
				cout << "0" << one[i] << ":";
			}
			else
			{
				cout << int(one[i]) - 55 << ":";
			}
			break;
		}
	}

	for (int i = 0; i < three.size(); i++)
	{
		if (three[i] == four[i] && isalpha(three[i]))
		{	
			if (i < 10)
				cout << 0 << i;
			else
				cout << i;
			break;
		}
	}
	system("pause");
	return 0;
}