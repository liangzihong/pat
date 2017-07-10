#include<iostream>
#include<string>
using namespace std;

int n = 0;



//用字符串类，打一个单词，用c=getchar（）吸收空格或者回车
//如果是空格，则递归进行，如果是回车，则不进行下一层递归了；
//递归结束开始，就开始输出；并且return；


void read(void)
{
	n++;
	int b = n;
	string a;
	cin >> a;
	char c = getchar();

	if (c != '\n')
	{
		read();
	}
	cout << a;
	if (b != 1)
	{
		cout<< " ";
	}
	return;
}

int main()
{
	read();
	system("pause");
	return 0;
}