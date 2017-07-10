#include<iostream>
#include<cctype>
using namespace std;

int main()
{
	int arr1[17] = { 7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2 };
	int jiaoyan[11] = { 1,0,'X',9,8,7,6,5,4,3,2 };
	char input[19];
	input[18] = 0;
	int allpass = 1;
	int T;
	int state;
	cin >> T;
	cin.get();
	for (int i = 0; i < T; i++) {
		state = 1;
		for (int i = 0; i < 18; i++) {
			input[i] = cin.get();
		}
		cin.get();  //³Ô»Ø³µ
		int res = 0;
		for (int i = 0; i < 17; i++) {
			if (isdigit(input[i]))
				res += arr1[i] * (input[i] - '0');
			else state = 0;
		}
		if (state == 1 && (jiaoyan[res % 11] == input[17] - '0' || res % 11 == 2 && input[17] == 'X'))
		{
		}
		else
		{
			allpass = 0;
			cout << input << endl;
		}
	}
		if (allpass)
			cout << "All passed\n";
		system("pause");
		return 0;
}