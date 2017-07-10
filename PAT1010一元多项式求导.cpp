#include<iostream>
using namespace std;


int main()
{
	bool state = true;
	int xishu;
	int zhishu;
	int result1;
	int result2;
	char ch;
	do{
		cin >> xishu >> zhishu;
		//cin.get();
		ch = cin.get();
		result1 = xishu*zhishu;
		result2 = zhishu - 1;
		if (result1 != 0 && result2 >= 0)
		{
			if(state==true)
			{
				state = false;
				cout << result1 << " " << result2;
			}
			else 
			{
				cout << " " << result1 << " " << result2;
			}
		}
	} while (ch!='\n');
	if (state == true)
		cout << "0 0";
	system("pause");
	return 0;
}