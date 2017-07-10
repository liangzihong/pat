#include<iostream>
#include<string>
#include<algorithm>
#include<cctype>
using namespace std;

//弱智题


int main()
{
	string bad = "";
	char ch;
	while ((ch = cin.get()) != '\n')
	{
		if (isalpha(ch)) {
			bad += tolower(ch);
		}
		bad += ch;                //大小写都录进错误输入中
	}
	char test;
	int cnt = 0;
	while ((test = cin.get()) != '\n')
	{
		if (bad.find('+') != string::npos) {          //大写肯定不行
			if (bad.find(test) == string::npos) {     //错误中没有这个字符
				if(isalpha(test)&&isupper(test)){}     //如果是字母，并且大写，不做任何处理
				else {
					cnt++;
					cout << test;
				}                    //其余的cout
			}
		}
		else {                                          //大写可以
			if (bad.find(test) == string::npos) {       //错误中没有这个字符
				cout << test; cnt++;
			}
		}
	}
	if (cnt == 0) {
		cout << endl;
	}
	system("pause");
	return 0;
}