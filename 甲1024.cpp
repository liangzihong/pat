#include<iostream>
#include<string>
using namespace std;

string addinverse(string source)
{
	string ret = "";
	string answer = "";
	for (int i = source.size() - 1; i >= 0;i--) {
		ret += source[i];
	}

	int jinwei = 0;
	for (int i = source.size() - 1; i >= 0; i--) {
		int newdigit = source[i] + ret[i] - '0' - '0' + jinwei;
		int gewei = newdigit % 10;
		jinwei = newdigit / 10;
		answer += (gewei + '0');
	}
	if (jinwei != 0) answer += (jinwei + '0');

	ret = "";
	for (int i = answer.size() - 1; i >= 0; i--) {
		ret += answer[i];
	}
	return ret;
}


int judge(string source)
{
	int len = source.size() - 1;
	for (int i = 0; i < source.size(); i++) {
		if (source[i] != source[len - i]) return 0;
	}
	return 1;
}

int main()
{
	string input;
	int cnt;
	cin >> input; cin >> cnt;
	int time = 0;
	while (judge(input) == 0 ) {
		input = addinverse(input);
		time++;
		if (time == cnt) break;
	}

	cout << input << endl << time;
	system("pause");
	return 0;


}