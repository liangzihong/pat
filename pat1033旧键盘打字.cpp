#include<iostream>
#include<string>
#include<algorithm>
#include<cctype>
using namespace std;

//������


int main()
{
	string bad = "";
	char ch;
	while ((ch = cin.get()) != '\n')
	{
		if (isalpha(ch)) {
			bad += tolower(ch);
		}
		bad += ch;                //��Сд��¼������������
	}
	char test;
	int cnt = 0;
	while ((test = cin.get()) != '\n')
	{
		if (bad.find('+') != string::npos) {          //��д�϶�����
			if (bad.find(test) == string::npos) {     //������û������ַ�
				if(isalpha(test)&&isupper(test)){}     //�������ĸ�����Ҵ�д�������κδ���
				else {
					cnt++;
					cout << test;
				}                    //�����cout
			}
		}
		else {                                          //��д����
			if (bad.find(test) == string::npos) {       //������û������ַ�
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