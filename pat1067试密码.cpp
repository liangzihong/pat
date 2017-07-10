#include<iostream>
#include<string>
using namespace std;

int main()
{
	string ans;
	int trynum;
	cin >> ans >> trynum;

	int has = 0;
	string input;
	cin.get();
	getline(cin, input);
	while (input != "#")
	{
		has++;
		if (has <= trynum&&input == ans) {
			cout << "Welcome in\n"; break;
		}
		if (has <= trynum&&input != ans) {
			cout << "Wrong password: " << input << endl;
		}
		if (has == trynum) {
			cout << "Account locked\n";
			break;
		}
		getline(cin, input);
	}
	system("pause");
	return 0;
}