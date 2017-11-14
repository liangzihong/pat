#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
	string temp;
	cin >> temp;

	int allcnt = temp.size();
	int sides = (allcnt + 2) / 3;
	int buttom = allcnt - 2 * sides;


	for (int i = 0; i < sides; i++) {
		cout << temp[i];
		if (i != sides - 1)
			for (int j = 0; j < buttom; j++) cout << " ";
		else
			for (int j = 1; j <= buttom; j++) cout << temp[i + j];
		cout << temp[allcnt - 1 - i] << endl;
	}
	system("pause");
	return 0;
}