#include<iostream>
#include<string>
#include<stack>
#include<algorithm>
using namespace std;

int main()
{
	string num;
	cin >> num;
	int*first = new int[10];
	int *second = new int[10];
	fill(first, first + 10, 0);
	fill(second, second + 10, 0);
	for (int i = 0; i < num.size()
		; i++) {
		first[num[i] - '0']++;
	}
	
	stack<int> answer;
	int jinwei = 0;
	for (int i = num.size()-1; i>=0; i--) {
		int dig = num[i] - '0';
		int newdig = dig * 2 + jinwei;
		answer.push(newdig % 10);
		jinwei = newdig / 10;
		second[newdig % 10]++;
	}
	if (jinwei != 0) answer.push(jinwei), second[jinwei]++;
	
	for (int i = 0; i < 10; i++) {
		if (first[i] != second[i]) {
			cout << "No" << endl; break;
		}
		if (i == 9) cout << "Yes" << endl;
	}

	while (answer.size() != 0) {
		cout << answer.top();
		answer.pop();
	}
	system("pause");
	return 0;
}